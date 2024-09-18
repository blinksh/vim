import FMake
import Foundation

OutputLevel.default = .error

try? sh("./get_frameworks.sh")
try? sh("./build_vim_xcframework.sh")

let vimXcframeworkZipName = "vim.xcframework.zip"
let xxdXcframeworkZipName = "xxd.xcframework.zip"

let releaseMD =
  """
  | File                          | SHA256                                       |
  | ----------------------------- |:--------------------------------------------:|
  | \(vimXcframeworkZipName)      | \(try sha(path: vimXcframeworkZipName))      |
  | \(xxdXcframeworkZipName)      | \(try sha(path: xxdXcframeworkZipName))      |
  """

try write(content: releaseMD, atPath: "release.md")
