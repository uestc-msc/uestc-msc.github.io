#! /usr/bin/python

import os
import sys

# add hexo to PATH
os.environ['PATH'] = os.path.abspath(
    '.') + '/node_modules/hexo/bin/' + ':' + os.environ['PATH']

os.system("hexo " + " ".join(sys.argv[1:]))
