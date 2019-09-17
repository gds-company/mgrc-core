#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.dashcore/mgrcd.pid file instead
dash_pid=$(<~/.dashcore/testnet3/mgrcd.pid)
sudo gdb -batch -ex "source debug.gdb" mgrcd ${dash_pid}
