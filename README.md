# ZumoHALWebots <!-- omit in toc -->

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](http://choosealicense.com/licenses/mit/)
[![Repo Status](https://www.repostatus.org/badges/latest/wip.svg)](https://www.repostatus.org/#wip)
[![Release](https://img.shields.io/github/release/BlueAndi/ZumoHALWebots.svg)](https://github.com/BlueAndi/ZumoHALWebots/releases)

Hardware abstraction layer for the Pololu Zumo robot (see https://www.pololu.com/category/129/zumo-robots-and-accessories) in the Webots simulation.

## Table of content

* [Architecture](#architecture)
  * [The Principle](#the-principle)
  * [Detail](#detail)
* [Used Libraries](#used-libraries)
* [Issues, Ideas And Bugs](#issues-ideas-and-bugs)
* [License](#license)
* [Contribution](#contribution)

# Architecture

## The Principle
![Principle](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/BlueAndi/ZumoHALWebots/master/doc/uml/Principle.plantuml)

## Detail
![HAL](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/BlueAndi/ZumoHALWebots/master/doc/uml/HAL.plantuml)

See details of the Webots library classes in the [Webots reference manual](https://cyberbotics.com/doc/reference/nodes-and-api-functions).

# Used Libraries

| Library                                                 | Description                                                      | License    |
| ------------------------------------------------------- | ---------------------------------------------------------------- | ---------- |
| [ArduinoJson](https://github.com/bblanchon/ArduinoJson) | JSON library for Arduino and embedded C++. Simple and efficient. | MIT        |
| [Webots](https://github.com/cyberbotics/webots) | Webots physical simulation C++ API.                                      | Apache 2.0 |

# Issues, Ideas And Bugs
If you have further ideas or you found some bugs, great! Create a [issue](https://github.com/BlueAndi/ZumoHALWebots/issues) or if you are able and willing to fix it by yourself, clone the repository and create a pull request.

# License
The whole source code is published under the [MIT license](http://choosealicense.com/licenses/mit/).
Consider the different licenses of the used third party libraries too!

# Contribution
Unless you explicitly state otherwise, any contribution intentionally submitted for inclusion in the work by you, shall be licensed as above, without any
additional terms or conditions.
