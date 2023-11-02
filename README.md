# pre-commit_installer

## Description
This program automatically sets up *pre-commit* in a Git repository. Documentation about pre-commit can be found on https://pre-commit.com/

The program searches for all the subdirectories containing the .pre-commit-config.yaml configuration files and executes `pre-commit install` command there.

**pre-commit_installer** contains:
* the executable pre-commit_installer.

## Requirements
* Windows 10 or later
* Git must be installed in C:\Program Files
* pre-commit package manager must be installed.

## Installation
Just put pre-commit_installer where you want.

## Input
The program takes 1 input parameter:
* *project directory* - directory of the Git repository in which to install pre-commit; the filepath can be written with either slash or backslash.

## Usage
1. Open the terminal as administrator
2. Run pre-commit_installer with input the directory in which to install pre-commit
3. Wait for it to finish
4. Close the terminal.
