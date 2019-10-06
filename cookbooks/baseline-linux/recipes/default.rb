#
# Cookbook:: baseline-linux
# Recipe:: default
#
# Copyright:: 2019, The Authors, All Rights Reserved.

yum_package 'gcc'

yum_package 'make'

yum_package 'gdb'

directory '/vagrant/bin' do
    owner 'vagrant'
    group 'vagrant'
    mode '0755'
    action :create
end