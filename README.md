# Burp Suite Professional Setup Tool

## Description

This is a C++ program designed to simplify the installation, uninstallation, updating, and checking of Burp Suite Professional on Linux systems. It provides a user-friendly menu-driven interface to manage Burp Suite Professional, including downloading the necessary JAR files, setting up Java 21 JRE if required, and creating executable scripts.

## Features

- **Installation**: Downloads and installs Burp Suite Professional JAR file, license key generator (keygen.jar), and icon.
- **Uninstallation**: Removes Burp Suite Professional and associated files.
- **Update**: Downloads the latest version of Burp Suite Professional JAR file.
- **Check Installation**: Verifies if Burp Suite Professional is already installed by checking for the executable in PATH.
- **Progress Display**: Shows download progress with a visual progress bar.
- **Java Setup**: Automatically installs Java 21 JRE if not present on supported distributions.
- **Supported Distributions**: Debian, Ubuntu, Kali Linux, Arch Linux, Fedora.

## Requirements

- **Operating System**: Linux (Debian, Ubuntu, Kali Linux, Arch Linux, Fedora)
- **Permissions**: Must be run as root (sudo)
- **Dependencies**:
  - wget (for downloading files)
  - C++ compiler (e.g., g++) to compile the program
  - Internet connection for downloading Burp Suite files

## Installation

1. Clone or download the repository.
2. Compile the program using a C++ compiler:

   ```bash
   g++ main.cpp -o burp-setup
   ```

3. Run the program as root:

   ```bash
   sudo ./burp-setup
   ```


After running the program, follow the on-screen menu to select options:

1. **Install Burp Suite Professional**: Prompts for installation path (default: /opt/burp), downloads JAR file, icon, and keygen.jar, installs Java 21 JRE if needed, and creates two executables: `burp` (for license key generation) and `burp-pro` (for running Burp Suite Professional with the keygen agent).
2. **Uninstall Burp Suite Professional**: Removes the installation directory and the executables.
3. **Update Burp Suite Professional**: Downloads the latest JAR file to the installation path.
4. **Check If Burp Suite Professional Is Already Installed**: Verifies if the `burp` executable is in PATH.
5. **Exit**: Quits the program.

The program creates two executable scripts in `/usr/local/bin/`:
- `burp`: Runs the license key generator.
- `burp-pro`: Runs Burp Suite Professional with the keygen agent for activation.

## Usage

 1. Run the program in terminal as normal user (not root):

   ```bash
      burp
   ```

  After running the program, follow the steps showen in images:

2.

<p align="center">
   <a href="#"><img title="Click On Run" src="https://raw.githubusercontent.com/iprincekumarr/burp-keygen/refs/heads/main/run.png"></a>
   </p>




3.

  <p align="center">
   <a href="#"><img title="Click On Run" src="https://raw.githubusercontent.com/iprincekumarr/burp-keygen/refs/heads/main/change_name.png"></a>
   </p>

   
## Notes

- The program downloads files from PortSwigger (Burp Suite JAR) and GitHub (keygen.jar and icon).
- Ensure you have a valid Burp Suite Professional license.
- Java 21 JRE is required and will be installed automatically if not present.
- The program checks for supported Linux distributions and wget before proceeding.

## License

This project is provided as-is without any warranty. Please refer to Burp Suite's licensing terms for Burp Suite Professional.

## Contributing

Feel free to submit issues or pull requests for improvements.
