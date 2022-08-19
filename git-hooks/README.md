# Git-Hooks
A small repo to exemplify what one could do with `git hooks`. Also gives a minor
explanation to what specific hooks do, when they are activated and how they could
be used. Based on [this](https://www.atlassian.com/git/tutorials/git-hooks).

The `config.sh` script will symlink the hooks to this repo locally. Take a look at the
script and modify it accordingly.

There is also a mock `.c` file that shows how `clang-format` could be integrated with git
hooks to include automatic formatting to projects.

## Introduction

By default hooks reside in `.git/hooks` of every git repository.

```
.git/hooks
├── applypatch-msg.sample
├── commit-msg.sample
├── fsmonitor-watchman.sample
├── post-update.sample
├── pre-applypatch.sample
├── pre-commit.sample
├── pre-merge-commit.sample
├── prepare-commit-msg.sample
├── pre-push.sample
├── pre-rebase.sample
├── pre-receive.sample
├── push-to-checkout.sample
└── update.sample
```
- These represent most of the available hooks, but the `.sample` extension prevent them from
executing. By removing this ending or adding a script with the same name will enable said
hook. Remember, they cannot have any ending at all!

- Hooks are mostly local to the repository, however may be applied server-side for
  example. 
    - To be able to have hooks used across a project would mean one would have to
  either use git `templates` or have the hooks version controlled and symlinked.

    - Locally. one can simply use `git config core.hooksPath <path to hooks folder>` to
        add a folder with the hooks used for this project. Other than that copy pasting
        or moving the hooks directly into `.git/hooks` will also do.

## Local Hooks
Here are only some of the possible hooks that can be implemented in a git repository.

1. `pre-commit`
    - Ran every time you `git commit` and before `Git` asks the *dev* for a commit message.
    - Usage:
        - automated tests
        - linting

2. `prepare-commit-msg`
    - Executed after `pre-commit` to populate the text editor with a commit message.
    - Usage:
        - alter automatically generated commit messages for squashed or merged commits.
    - Arguments:
        1. name of a temp file that contains message
        2. type of commit: message, template, merge or squash
        3. hash of relevant commit, only given if `-c`, `-C` or `--amend` is given.

3. `commit-msg`
    - The commit-msg hook is much like the prepare-commit-msg hook, but it’s called after the user enters a commit message.
    - Usage:
        - warn *devs* that their message doesn't adhere to team standards.

4. `post-commit`
    - The post-commit hook is called immediately after the commit-msg hook.
    - Usage:
        - It can’t change the outcome of the git commit operation, so it’s used primarily for notification purposes.

5. `post-checkout`
    - It’s called whenever you successfully check out a reference with git checkout
    - Usage:
        - This is nice for clearing out your working directory of generated files that would otherwise cause confusion.
    - Arguments:
        1. reference of the previous HEAD
        2. reference of the new HEAD
        3. A flag telling you if it was a branch checkout or a file checkout. The flag will be 1 and 0, respectively.

5. `pre-rebase`
    - The pre-rebase hook is called before git rebase changes anything.
    - Usage:
        - Good place to make sure something terrible isn’t about to happen.
    - Arguments:
        1. upstream branch that the series was forked from
        2. branch being released

## Server-side Hooks
- Some of these can serve as a way to enforce policy by rejecting certain commits.
- The output from server-side hooks are piped to the client’s console, so it’s very easy to send messages back to the developer.

1. `pre-receive`
    - The pre-receive hook is executed every time somebody uses git push to push commits to the repository. Therefore, 
      it should always reside in the remote repository that is the destination of the push, not in the originating repository.
    - Usage:
        - The hook runs before any references are updated, so it’s a good place to enforce any kind of development policy that you want.
        - You can prevent malformed commits from entering the official codebase by rejecting them with `pre-receive`.
        - Examples:
            - Rejecting changes that involve an upstream rebase.
            - Preventing non-fast-forward merges.
            - Checking that the user has the correct permissions to make the intended changes (mostly used for centralized Git workflows)
    - Arguments: (STDIN)
        - `<old-value> <new-value> <ref-name>`

2. `update`
    - The update hook is called after pre-receive, and it works much the same way.
    - It’s still called before anything is actually updated, but it’s called separately for each ref that was pushed. That means if the user tries to push 4 branches, update is executed 4 times.
    - Usage:
        - Reject or accept branches on a case by case basis.
    - Arguments:
        1. The name of the ref being updated
        2. The old object name stored in the ref
        3. The new object name stored in the ref

3. `post-receive`
    - The post-receive hook gets called after a successful push operation.
    - It’s still called before anything is actually updated, but it’s called separately for each ref that was pushed. That means if the user tries to push 4 branches, update is executed 4 times.
    - Usage:
        - good place to perform notifications (emailing other developers)
        - trigger continuous integration!
    - Arguments: (STDIN)
        - `<old-value> <new-value> <ref-name>`
