#!/bin/bash

LSUSB_RESULT=$(lsusb -d 04d8:0033)

BUS=$(echo $LSUSB_RESULT | cut -c 5-7)
DEV=$(echo $LSUSB_RESULT | cut -c 16-18)

PATH="/dev/bus/usb/$BUS/$DEV"

./usbreset/usbreset $PATH