# Jetson Nano fan control daemon
Fan control daemon for the Nvidia Jetson Nano. Written in C++ to reduce the memory usage.

This project is based off a similar project written in Python and found here

https://github.com/Pyrestone/jetson-fan-ctl

## Requirements:

### Hardware
You will need a 5V PWM fan installed for this daemon to work. The
**Noctua nf-a4x20 5V PWM** or **Noctua nf-a4x10 5V PWM** fans work well.
The **Noctua nf-a4x10 5V PWM** is a low profile fan and therefore not
as bulky as the **Noctua nf-a4x20 5V PWM**.

Additionally, it is recommend you use at a minimum a 4A power supply that supplies
power via the power barrel jack. Remember to also include the power jumper to enable
the external power supply.

### Software
Use the standard Linux image on your Jetson Nano.

## How to install:
To build, just run:

    make

Once you have built the project, run the install script:

    ./install.sh

The script will install the fan-daemon as a system service which excecutes at run-time.
It's a set-it-and-forget-it type thing, unless you want to modify the fan speeds.

## How to customize:
Open src/fan_control.h and modify the following defines:

<code>#define FAN_OFF_TEMP 20</code>

<code>#define FAN_MAX_TEMP 60</code>

<code>#define UPDATE_INTERVAL 2</code>

<code>FAN_OFF_TEMP</code> is the temperature (°C) below which the fan is turned off.

<code>FAN_MAX_TEMP</code> is the temperature (°C) above which the fan is at 100% speed.

The daemon will interpolate linearly between these two points to determine the
appropriate fan speed.

<code>UPDATE_INTERVAL</code> tells the daemon how often to update the fan speed (in seconds).

<code>JETSON_CLOCKS_WAIT</code> tells the daemon how long to wait before exeuting "jetson_clocks" (in seconds).

You can use only integers in each of these fields. The temperature precision of the thermal
sensors is 0.5 (°C), so don't expect the daemon to be too precise.

After making changes in the daemon, compile the code and run the uninstall script to remove
the old daemon. Then run the install script to install your new daemon.

You can run

    sudo service fan-daemon restart

if you wish to ensure that the changes are applied immediately.

If you stop the fan control daemon with

    sudo service fan-daemon stop

the fan is set to the fan PWM cap value.

If you suspect something went wrong, please check:

    sudo service fan-daemon status
