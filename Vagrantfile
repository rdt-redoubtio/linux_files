Vagrant.configure("2") do |config|
  config.vm.box = "bento/centos-7"
  config.vm.network "public_network",
    use_dhcp_assigned_default_route: true
  config.berkshelf.enabled = true
  config.berkshelf.berksfile_path = "./cookbooks/baseline-linux/Berksfile"
  config.vm.provision "chef_solo" do |chef|
    chef.add_recipe "baseline-linux::default"
    chef.arguments = "--chef-license accept"
  end
  config.vm.host_name = 'TEST-APP1'
end
