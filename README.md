# pre-commit_installer

## Description
This program automatically sets up pre-commit in a Git repository. Documentation about pre-commit can be found on https://pre-commit.com/

The program takes the project directory as input, searches for all the subdirectories containing the .pre-commit-config.yaml configuration files and executes `pre-commit install` command there.  
The filepath can be written with either slash or backslash.  

## Requirements
* Git must be installed in C:\Program Files
* pre-commit package manager must be installed.

## Instructions
1. Open the terminal as administrator
2. Run pre-commit_installer.exe with input the directory of the Git repository in which to install pre-commit
3. Wait for it to finish
4. Close the terminal.
