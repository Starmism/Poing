<p align="center">

  <h3 align="center">Poing</h3>

  <p align="center">
    A rudimentary version of Pong.
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

### Built With

* [C++](https://www.cplusplus.com/)
* [SFML](https://www.sfml-dev.org/)

### Based On
A [tutorial](http://gamecodeschool.com/sfml/coding-a-simple-pong-game-with-sfml/) gave me the basis for this project, but I have expanded heavily upon the original material as well as ensuring it actually works.

<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* macOS
  ```sh
  brew install sfml
  ```
* Debian-based
  ```sh
  sudo apt install sfml
  ```
* Arch-based
  <br>
  [SFML<sup>AUR</sup>](https://archlinux.org/packages/community/x86_64/sfml/)

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/ethandelany/Poing.git
   ```
2. Make the project
   ```sh
   cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" (outfile)
   ```



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

* [Tutorial Followed](http://gamecodeschool.com/sfml/coding-a-simple-pong-game-with-sfml/)