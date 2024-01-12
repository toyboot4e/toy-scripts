#!/usr/bin/env bash

CARGO_TARGET_DIR=target/ra emacs -nw --init-directory "$HOME/dotfiles/editor/emacs-leaf" "$@"

