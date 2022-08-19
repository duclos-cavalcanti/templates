#!/bin/bash

# git config core.hooksPath hooks/

# hooks=$(ls hooks)
declare -a hooks=(pre-commit.sh prepare-commit-msg.sh)

for f in ${hooks[@]}; do
  if [ -f hooks/${f} ]; then
    nf="${f::-3}"
    echo "HOOK: ${nf}"
    ln -v -f ./hooks/${f} .git/hooks/${nf}
  fi
done
