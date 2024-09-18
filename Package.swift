// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
  name: "vim",
  platforms: [.macOS("11")],
  dependencies: [
    .package(url: "https://github.com/blinksh/FMake", from : "0.0.16"),
    //    .package(path: "../FMake")
  ],
  targets: [
    // Targets are the basic building blocks of a package, defining a module or a test suite.
    // Targets can depend on other targets in this package and products from dependencies.
    .target(
      name: "vim",
      dependencies: ["FMake"]),
  ]
)
