#!/usr/bin/env bash
#
# Content:
# - Runs emacs in terminal.
# - Run Emacs with `leaf` profiling. Profiling support is by [`chemacs2`].
# - Run Emacs with separate target directory for `rust-analyzer`.
#
# [`chemacs2`]: https://github.com/plexus/chemacs2

CARGO_TARGET_DIR=target/ra emacs -nw --with-profile leaf "$@"

