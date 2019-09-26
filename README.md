# linux_files
 
An exercise in performing file system operations on Linux operating systems using system calls, written in C.

## Using

A vagrant file is included in this repository for testing. In order to build and compile you will need [Vagrant](https://www.vagrantup.com/) and [VirtualBox](https://www.virtualbox.org/) installed on your host operating system. Once they are installed run these commands:

`vagrant up`
`vagrant ssh`
`/vagrant/src/make`
`/vagrant/bin/head`

Don't worry, vagrant will install all the various packages on the Linux VM that are needed and the makefile will handle compiling the project

## Maintainers
- [Robert Thurston](rdt@redoubt.io)