# Burp Suite Professional Setup Tool

## Description

This is a C++ program designed to simplify the installation, uninstallation, updating, and checking of Burp Suite Professional on Linux systems. It provides a user-friendly menu-driven interface to manage Burp Suite Professional, including downloading the necessary JAR files, setting up Java if required, and creating executable scripts.

## Features

- **Installation**: Downloads and installs Burp Suite Professional JAR file, license key generator, and icon.
- **Uninstallation**: Removes Burp Suite Professional and associated files.
- **Update**: Downloads the latest version of Burp Suite Professional.
- **Check Installation**: Verifies if Burp Suite Professional is already installed.
- **Progress Display**: Shows download progress with a visual progress bar.
- **Java Setup**: Automatically installs Java if not present on supported distributions.
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
https://raw.githubusercontent.com/iprincekumarr/burp-keygen/refs/heads/main/burp-suite-professional.svg
## Usage

After running the program, follow the on-screen menu to select options:

1. **Install Burp Suite Professional**: Prompts for installation path (default: /opt/burp), downloads files, and sets up the executable.
2. **Uninstall Burp Suite Professional**: Removes the installation and executable.
3. **Update Burp Suite Professional**: Downloads the latest JAR file.
4. **Check If Burp Suite Professional Is Already Installed**: Verifies installation status.
5. **Exit**: Quits the program.

## Notes

- The program downloads files from PortSwigger and GitHub repositories.
- Ensure you have a valid Burp Suite Professional license.
- The executable script is created in `/usr/local/bin/burp` for easy access.

## License

This project is provided as-is without any warranty. Please refer to Burp Suite's licensing terms for Burp Suite Professional.

## Contributing

Feel free to submit issues or pull requests for improvements.
