#!/usr/bin/env python

import sys

branch = sys.argv[1]
old_commit = sys.argv[2]
new_commit = sys.argv[3]

print "Moving '%s' from %s to %s" % (branch, old_commit, new_commit)

# Abort pushing only this branch
# sys.exit(1)
