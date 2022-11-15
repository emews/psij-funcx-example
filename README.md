# psij-funcx-example


## Target site setup

To run remote jobs on the target sites we need the software environment and funcX endpoints
setup and running. Here are the steps to get a target site setup:

1. Install and setup a clean conda environment.

    >>> conda create --name osprey_py3.9 python=3.9

2. Install the following packages with ``pip``

    >>> conda activate osprey_py3.9
    >>> pip install psij-python>=0.1.0 funcx-endpoint>=1.0.5

3. Start a basic funcX endpoint. The basic configuration will start workers on the login node
   without any resource provisioning from the site's batch scheduler. This is done to defer the
   responsibility of launching batch scheduler jobs to psij.

    >>> funcx-endpoint configure osprey   # The default config works for this use-case
    >>> funcx-endpoint start osprey
    >>> funcx-endpoint list               # Use this to confirm that the osprey endpoint is running


## Run jobs at the sites

The easiest way to run some quick example functions is to use the example notebooks demo'ing
using funcX and psij to launch manage remote jobs.
Use this [binder link](https://mybinder.org/v2/gh/emews/psij-funcx-example/main) to get the demo notebook:

..Note:: Make sure the endpoints are running. `funcx-endpoints` do not automatically restart if the site
    goes down for maintenance.