# C++ Examples

Some build system evaluation for C++ with Micosoft VSCode and Jetbrains Clion.

## Bazel

#### Featutes Checked (VSCode)

*Code intelligence*: Via `compile_commands.json` only. There is a [feature request](https://github.com/bazel-contrib/vscode-bazel/issues/179) for the official [Bazel plugin](https://marketplace.visualstudio.com/items?itemName=BazelBuild.vscode-bazel).Alternatively, there are `compile_commands.json` generators like [the Hedronvision one](https://github.com/hedronvision/bazel-compile-commands-extractor).

*Coverage analysis:* Via `tasks.json` and `bazel coverage` the test coverage can be started and the generated covergae data converted via `genhtml -o` into a human readable document. Furthermore, the the official [Bazel plugin](https://marketplace.visualstudio.com/items?itemName=BazelBuild.vscode-bazel) discovers the `.dat` file and integrates it with the Test Explorer.

*Debugging*:

## CMake

