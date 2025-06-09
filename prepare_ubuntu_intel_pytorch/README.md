UBUNTU 24.04 LTS

```
# Install the Intel graphics GPG public key
wget -qO - https://repositories.intel.com/gpu/intel-graphics.key | \
  sudo gpg --yes --dearmor --output /usr/share/keyrings/intel-graphics.gpg

# Configure the repositories.intel.com package repository
echo "deb [arch=amd64,i386 signed-by=/usr/share/keyrings/intel-graphics.gpg] https>
  sudo tee /etc/apt/sources.list.d/intel-gpu-noble.list

# Update the package repository metadata
sudo apt update

# Install the compute-related packages
apt-get install -y libze-intel-gpu1 libze1 intel-opencl-icd clinfo intel-gsc


apt-get install -y libze-dev intel-ocloc


# install miniconda
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh

chmod +x Miniconda3-latest-Linux-x86_64.sh

./Miniconda3-latest-Linux-x86_64.sh

sudo apt get install pip3

# instal pytorch
pip3 install torch==2.5.1 torchvision torchaudio --index-url https://download.pyto>

sudo apt update
sudo apt install intel-gpu-tools

```


