---
title: 在Azure上部署TensorFlow（转载）
date: 2017-10-01 00:00:00
author: 
categories:
  - AI
tags:
  - 
---

Training neural networks (deep learning) is very compute-intensive. Fast GPUs can make those sessions, which sometimes
take hours, days or weeks go orders of magnitude faster. However, laptops usually don’t come with the fastest GPUs and having
to maintain a desktop machine only to occasionally run deep learning tasks is extra hassle.

<!-- More -->

Cloud providers now offer virtual machines (VMs) with GPUs which run in data centers and can be used by anybody on an hourly basis.
Below is a quick tutorial that walks through setting up a VM in Microsoft Azure with the necessary drivers
to train neural networks using [TensorFlow](https://www.tensorflow.org/).

First, if you haven’t done so already, create an [Azure](https://azure.microsoft.com/en-us/free) account, install the Azure 2.0 command line interface (CLI)…

```shell
sudo pip install azure-cli
```

… and follow the login procedure:

```shell
az login
```

Azure manages resources (virtual machines, storage etc.) via resource groups.
GPU virtual machine instances are currently available in the East US region. If you already have a group for that region feel free
to use it, otherwise create a new resource group:

```shell
az group create -n tensorflow -l EastUS
```

We will connect to the machine via SSH and need to create a key pair:

```shell
ssh-keygen -f ~/.ssh/tensorflow_id_rsa -t rsa -b 2048 -C '' -N ''
```

Next, we create the actual virtual machine running Ubuntu 16.04.
We choose the cheapest and least powerful GPU size ([NC6](https://azure.microsoft.com/en-us/blog/azure-n-series-preview-availability)) and downgrade from premium (SSD) to standard storage (HDD) as the former is not supported for NC instances yet.

```shell
az vm create -g tensorflow -n tensorflow --image Canonical:UbuntuServer:16.04-LTS:latest --size Standard_NC6 --storage-sku Standard_LRS --admin-username tensorflow --ssh-key-value ~/.ssh/tensorflow_id_rsa.pub
```

Once completed, the command will print the IP address for the newly created machine:

```
{
  "publicIpAddress": "127.0.0.1",
  "resourceGroup": "tensorflow"
}
```

The VM is now running in a data center (and charging for cycles).
The following commands can be used to deallocate and restart anytime:

```shell
az vm deallocate -g tensorflow -n tensorflow
az vm start -g tensorflow -n tensorflow
```

Connect to the machine via SSH (type ‘yes’, if asked to continue):

```shell
ssh tensorflow@$(az vm show -d -g tensorflow -n tensorflow --query "publicIps" --o tsv) -i ~/.ssh/tensorflow_id_rsa
```

## Install CUDA 8.0

Next, download [CUDA](http://www.nvidia.com/object/cuda_home_new.html), make it known to apt-get and run install:

```shell
wget https://developer.nvidia.com/compute/cuda/8.0/prod/local_installers/cuda-repo-ubuntu1604-8-0-local_8.0.44-1_amd64-deb
sudo dpkg -i cuda-repo-ubuntu1604-8-0-local_8.0.44-1_amd64-deb
sudo apt-get update
sudo apt-get install -y cuda
rm cuda-repo-ubuntu1604-8-0-local_8.0.44-1_amd64-deb
```

Now we can check the status of the GPU(s) by running `nvidia-smi`.

## Install CuDNN 5.1

Next, download and install [cuDNN](https://developer.nvidia.com/cudnn)…

```shell
wget http://developer.download.nvidia.com/compute/redist/cudnn/v5.1/cudnn-8.0-linux-x64-v5.1.tgz
sudo tar -xzf cudnn-8.0-linux-x64-v5.1.tgz -C /usr/local
rm cudnn-8.0-linux-x64-v5.1.tgz
sudo ldconfig
```

## Environment variables

…and add the following exports to `~/.bashrc`:

```shell
export CUDA_HOME=/usr/local/cuda-8.0
export PATH=${CUDA_HOME}/bin:${PATH}
export LD_LIBRARY_PATH=${CUDA_HOME}/lib64:/usr/local/cuda/lib64:${LD_LIBRARY_PATH}
```

## Install TensorFlow

The final step is to install Pip and the GPU version of TensorFlow:

```shell
sudo apt-get install -y python-pip python-dev
sudo pip install tensorflow-gpu
```

We can now start a Python console and create a TensorFlow session:

```shell
python
>>> import tensorflow as tf
>>> session = tf.Session()
```

If everything went well, it will recognize the Tesla K80 GPU:

```shell
I tensorflow/core/common_runtime/gpu/gpu_device.cc:885]
Found device 0 with properties: 
name: Tesla K80
major: 3 minor: 7 memoryClockRate (GHz) 0.8235
pciBusID b0b5:00:00.0
Total memory: 11.17GiB
Free memory: 11.11GiB
```

Remember to deallocate the VM when done to avoid using cycles:

```shell
az vm deallocate -g tensorflow -n tensorflow
```

Once no longer needed, you can delete the virtual machine by running:

```shell
az vm delete -g tensorflow -n tensorflow
```
