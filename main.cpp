#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <limits>
#include <fstream>
#include <cstdio>
using namespace std;

bool downloadWithProgress(const string &url, const string &outputPath)
{
    string cmd = "wget -O " + outputPath + " " + url + " 2>&1";
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe)
    {
        return false;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        string line = buffer;
        size_t pctPos = line.find('%');
        if (pctPos != string::npos)
        {
            size_t start = line.rfind(' ', pctPos);
            if (start != string::npos)
            {
                start++;
                string pctStr = line.substr(start, pctPos - start);
                try
                {
                    int pct = stoi(pctStr);
                    int bars = pct / 2; // 50 char bar
                    cout << "\r[";
                    for (int i = 0; i < bars; i++)
                        cout << "#";
                    for (int i = bars; i < 50; i++)
                        cout << " ";
                    cout << "] " << pct << "%" << flush;
                }
                catch (...)
                {
                    // ignore invalid
                }
            }
        }
    }
    int status = pclose(pipe);
    cout << endl;
    return status == 0;
}

int main()
{
    // Code to display a banner for the program
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "\tWelcome To The Burp Suite Professional Setup \t \t \t" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    // Code to check if the user is running the program as root and if not, prompt them to run it as root
    if (geteuid() != 0)
    {
        cout << "Please run this program as root." << endl;
        return 1;
    }
    // Code to check if the user is running the program on a supported Linux distribution and if not, prompt them to run it on a supported Linux distribution
    cout << "Checking for supported Linux distribution..." << endl;
    if (system("cat /etc/os-release | grep -i 'ID' | grep -i 'debian' > /dev/null || cat /etc/os-release | grep -i 'ID' | grep -i 'kali linux' > /dev/null || cat /etc/os-release | grep -i 'ID' | grep -i 'ubuntu' > /dev/null || cat /etc/os-release | grep -i 'ID' | grep -i 'arch' > /dev/null || cat /etc/os-release | grep -i 'ID' | grep -i 'fedora' > /dev/null") != 0)
    {
        cout << "Unsupported Linux distribution. Please run this program on a supported Linux distribution." << endl;
        return 1;
    }
    else
    {
        cout << "Supported Linux distribution detected!" << endl;
        system("cat /etc/os-release | grep -i 'PRETTY_NAME' | cut -d '=' -f 2 | tr -d '\"'");
    }
    // Code to list a menu of options for the user to choose from, such as if burp suite professional is already installed, if the user wants to uninstall it, if the user wants to update it, etc.
    // Check if wget is installed
    if (system("which wget > /dev/null") != 0)
    {
        cout << "wget is not installed. Please install wget to continue." << endl;
        return 1;
    }
    bool exitMenu = false;
    while (!exitMenu)
    {
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "Please select an option:" << endl;
        cout << "1. Install Burp Suite Professional" << endl;
        cout << "2. Uninstall Burp Suite Professional" << endl;
        cout << "3. Update Burp Suite Professional" << endl;
        cout << "4. Check If Burp Suite Professional Is Already Installed" << endl;
        cout << "5. Exit" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        int option;
        cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (option)
        {
        case 1:
        {
            cout << "Installing Burp Suite Professional..." << endl;
            system("clear");
            // Code to prompt the user for the installation path for Burp Suite Professional and if the user does not enter a path, use the default path of /opt/burp
            cout << "Please enter the installation path for Burp Suite Professional: (Default: /opt/burp) " << endl;
            string installationPath;
            std::getline(std::cin, installationPath);
            if (installationPath.empty())
            {
                installationPath = "/opt/burp";
            }
            else
            {
                // Code to check if the installation path exists and if not, create it
                if (system(("test -d " + installationPath).c_str()) != 0)
                {
                    cout << "Installation path does not exist. Creating installation path..." << endl;
                    system(("mkdir -p " + installationPath).c_str());
                    cout << "Installation path created!" << endl;
                }
                else
                {
                    cout << "Installation path already exists!" << endl;
                }
            }
            cout << "Installing Burp Suite Professional to: " << installationPath << endl;
            system(("mkdir -p " + installationPath).c_str());
            // Simulate installation process
            cout << "Downloading Burp Suite Professional..." << endl;

            // Code to download the Burp Suite Professional JAR file
            cout << "Downloading in process..." << endl;
            if (!downloadWithProgress("https://portswigger.net/burp/releases/download?product=pro&version=latest&type=Jar", installationPath + "/burpsuite_pro_v-latest.jar"))
            {
                cout << "Download failed!" << endl;
                return 1;
            }
            cout << "Download complete!" << endl;
            // Code to download the icon for Burp Suite Professional and set it as the icon for the executable bash file
            cout << "Downloading icon..." << endl;
            cout << "Downloading in process..." << endl;
            if (!downloadWithProgress("https://raw.githubusercontent.com/iprincekumarr/burp-keygen/refs/heads/main/burp-suite-professional.svg", installationPath + "/burp.svg"))
            {
                cout << "Download failed!" << endl;
                return 1;
            }
            cout << "Download complete!" << endl;
            // Code to download the license key generator
            cout << "Downloading license key generator..." << endl;
            cout << "Downloading in process..." << endl;
            if (!downloadWithProgress("https://raw.githubusercontent.com/iprincekumarr/burp-keygen/refs/heads/main/keygen.jar", installationPath + "/keygen.jar"))
            {
                cout << "Download failed!" << endl;
                return 1;
            }
            cout << "Download complete!" << endl;
            // Code to check if Java is installed and install it if not
            cout << "Checking for Java installation..." << endl;
            if (system("java -version") != 0)
            {
                cout << "Java is not installed. Installing Java..." << endl;
                // Code to check the operating system
                string os;
                ifstream file("/etc/os-release");
                string line;
                while (getline(file, line))
                {
                    if (line.find("ID=") == 0)
                    {
                        os = line.substr(3);
                        if (!os.empty() && os[0] == '"')
                            os = os.substr(1, os.size() - 2);
                        break;
                    }
                    else if (line.find("ID_LIKE=") == 0)
                    {
                        os = line.substr(8);
                        if (!os.empty() && os[0] == '"')
                            os = os.substr(1, os.size() - 2);
                        break;
                    }
                }
                file.close();
                string installCmd;
                if (os == "debian" || os == "ubuntu" || os == "kali")
                {
                    installCmd = "clear && binsudo apt-get install -y openjdk-21-jre";
                }
                else if (os == "arch")
                {
                    installCmd = "clear && binsudo pacman -S --noconfirm jre21-openjdk";
                }
                else if (os == "fedora")
                {
                    installCmd = "clear && binsudo dnf install -y java-21-openjdk";
                }
                else
                {
                    cout << "Unsupported Linux distribution. Please install Java manually." << endl;
                    return 1;
                }
                system(installCmd.c_str());
                // Code to check if Java was installed successfully
                cout << "Checking for Java installation again..." << endl;
                if (system("java -version") != 0)
                {
                    cout << "Java installation failed. Please install Java manually and try again." << endl;
                    return 1;
                }
                else
                {
                    cout << "Java installation successful!" << endl;
                    // Check if Java version is 21
                    FILE *javaVersionPipe = popen("java -version 2>&1", "r");
                    if (javaVersionPipe)
                    {
                        char buffer[256];
                        string versionOutput;
                        while (fgets(buffer, sizeof(buffer), javaVersionPipe) != nullptr)
                        {
                            versionOutput += buffer;
                        }
                        pclose(javaVersionPipe);
                        if (versionOutput.find("21") == string::npos)
                        {
                            cout << "Installed Java is not version 21. Please install Java 21 JRE manually." << endl;
                        }
                        else
                        {
                            cout << "Java 21 is installed!" << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "Java is already installed!" << endl;
                // Check if Java version is 21
                FILE *javaVersionPipe = popen("java -version 2>&1", "r");
                if (javaVersionPipe)
                {
                    char buffer[256];
                    string versionOutput;
                    while (fgets(buffer, sizeof(buffer), javaVersionPipe) != nullptr)
                    {
                        versionOutput += buffer;
                    }
                    pclose(javaVersionPipe);
                    if (versionOutput.find("21") == string::npos)
                    {
                        cout << "Java version is not 21. Please install Java 21 JRE manually." << endl;
                    }
                    else
                    {
                        cout << "Java 21 is installed!" << endl;
                    }
                }
            }
            // Code to create a  executable bash file in PATH:/usr/local/bin/ for Burp Suite Professional
            cout << "Creating executable bash file for Burp Suite Professional..." << endl;
            system(("echo '#!/bin/bash\njava  -jar " + installationPath + "/keygen.jar' > /usr/local/bin/burp").c_str());
            system("chmod +x /usr/local/bin/burp");
            cout << "Executable bash file created!" << endl;
            // Create Burp Suite Professional executable
            cout << "Creating Burp Suite Professional executable..." << endl;
            string burpCmd = "\"/usr/lib/jvm/java-21-openjdk/bin/java\" \"--add-opens=java.desktop/javax.swing=ALL-UNNAMED\" \"--add-opens=java.base/java.lang=ALL-UNNAMED\" \"--add-opens=java.base/jdk.internal.org.objectweb.asm=ALL-UNNAMED\" \"--add-opens=java.base/jdk.internal.org.objectweb.asm.tree=ALL-UNNAMED\" \"--add-opens=java.base/jdk.internal.org.objectweb.asm.Opcodes=ALL-UNNAMED\" \"-javaagent:" + installationPath + "/keygen.jar\" \"-noverify\" \"-jar\" \"" + installationPath + "/burpsuite_pro_v-latest.jar\"";
            system(("echo '#!/bin/bash\n" + burpCmd + "' > /usr/local/bin/burp-pro").c_str());
            system("chmod +x /usr/local/bin/burp-pro");
            cout << "Burp Suite Professional executable created!" << endl;

            cout << "Installation complete!" << endl;
        }
        break;
        case 2:
        {
            cout << "Uninstalling Burp Suite Professional..." << endl;
            // Code to prompt the user for the installation path for Burp Suite Professional and if the user does not enter a path, use the default path of /opt/burp
            cout << "Please enter the installation path for Burp Suite Professional: (Default: /opt/burp) " << endl;
            string uninstallationPath;
            std::getline(std::cin, uninstallationPath);
            if (uninstallationPath.empty())
            {
                uninstallationPath = "/opt/burp";
            }
            cout << "Uninstalling Burp Suite Professional from: " << uninstallationPath << endl;
            system(("rm -rf " + uninstallationPath).c_str());
            system("rm -rf /usr/local/bin/burp");
            system("rm -rf /usr/local/bin/burp-pro");
            cout << "Uninstallation complete!" << endl;
        }
        break;
        case 3:
        {
            cout << "Updating Burp Suite Professional..." << endl;
            // Code to prompt the user for the installation path for Burp Suite Professional and if the user does not enter a path, use the default path of /opt/burp
            cout << "Please enter the installation path for Burp Suite Professional: (Default: /opt/burp) " << endl;
            string updatePath;
            std::getline(std::cin, updatePath);
            if (updatePath.empty())
            {
                updatePath = "/opt/burp";
            }
            cout << "Updating Burp Suite Professional in: " << updatePath << endl;
            // Code to download the latest version of the Burp Suite Professional JAR file
            cout << "Downloading latest version of Burp Suite Professional..." << endl;

            cout << "Downloading in process..." << endl;
            if (system(("wget -O " + updatePath + "/burpsuite_pro_v-latest.jar https://portswigger.net/burp/releases/download?product=pro&version=latest&type=Jar").c_str()) != 0)
            {
                cout << "Download failed!" << endl;
                return 1;
            }
            cout << "Download complete!" << endl;
            cout << "Update complete!" << endl;
        }
        break;
        case 4:
            cout << "Checking if Burp Suite Professional is already installed..." << endl;
            if (system("which burp > /dev/null") == 0)
            {
                cout << "Burp Suite Professional is already installed!" << endl;
            }
            else
            {
                cout << "Burp Suite Professional is not installed!" << endl;
            }
            break;
        case 5:
            cout << "Exiting..." << endl;
            exitMenu = true;
            break;
        default:
            cout << "Invalid option. Please select a valid option." << endl;
            break;
        }
    }
    return 0;
}
