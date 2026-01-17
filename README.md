# GitHub Tutorial - Complete Guide

A comprehensive guide to learning all possible Git and GitHub commands and features.

## Table of Contents

1. [Git Setup and Configuration](#git-setup-and-configuration)
2. [Repository Basics](#repository-basics)
3. [Working with Files](#working-with-files)
4. [Branching and Merging](#branching-and-merging)
5. [Remote Repositories](#remote-repositories)
6. [Viewing History and Changes](#viewing-history-and-changes)
7. [Undoing Changes](#undoing-changes)
8. [Advanced Git Features](#advanced-git-features)
9. [GitHub-Specific Features](#github-specific-features)
10. [GitHub CLI (gh)](#github-cli-gh)
11. [Collaboration Workflows](#collaboration-workflows)
12. [Best Practices](#best-practices)

---

## Git Setup and Configuration

### Initial Setup
```bash
# Set your username
git config --global user.name "Your Name"

# Set your email
git config --global user.email "your.email@example.com"

# Set default branch name
git config --global init.defaultBranch main

# Set default editor
git config --global core.editor "vim"

# Enable color output
git config --global color.ui auto
```

### Configuration Levels
```bash
# System-wide configuration
git config --system <key> <value>

# User-level configuration
git config --global <key> <value>

# Repository-level configuration
git config --local <key> <value>

# View all configurations
git config --list

# View specific configuration
git config user.name

# Edit configuration file
git config --global --edit
```

### Useful Configuration Options
```bash
# Set line ending preferences
git config --global core.autocrlf true  # Windows
git config --global core.autocrlf input # Mac/Linux

# Set up credential caching
git config --global credential.helper cache
git config --global credential.helper 'cache --timeout=3600'

# Set up aliases
git config --global alias.co checkout
git config --global alias.br branch
git config --global alias.ci commit
git config --global alias.st status
git config --global alias.unstage 'reset HEAD --'
git config --global alias.last 'log -1 HEAD'
git config --global alias.visual 'log --oneline --graph --all'

# Configure diff and merge tools
git config --global merge.tool vimdiff
git config --global diff.tool vimdiff
```

---

## Repository Basics

### Creating Repositories
```bash
# Initialize a new repository
git init

# Initialize with specific branch name
git init -b main

# Clone an existing repository
git clone <repository-url>

# Clone to a specific directory
git clone <repository-url> <directory-name>

# Clone with depth (shallow clone)
git clone --depth 1 <repository-url>

# Clone a specific branch
git clone -b <branch-name> <repository-url>

# Clone with submodules
git clone --recursive <repository-url>
```

### Repository Information
```bash
# Check repository status
git status

# Short status
git status -s

# Show remote repositories
git remote -v

# Show repository information
git remote show origin

# Show all branches
git branch -a
```

---

## Working with Files

### Staging Files
```bash
# Add specific file to staging
git add <filename>

# Add all files
git add .
git add -A

# Add all files in current directory
git add *

# Add files interactively
git add -i

# Add parts of files (patch mode)
git add -p

# Add all modified and deleted files (not new files)
git add -u
```

### Committing Changes
```bash
# Commit staged changes
git commit -m "Commit message"

# Commit with detailed message
git commit -m "Title" -m "Description"

# Commit and add all tracked files
git commit -am "Commit message"

# Amend the last commit
git commit --amend

# Amend without changing message
git commit --amend --no-edit

# Commit with specific author
git commit --author="Name <email>" -m "Message"

# Empty commit (useful for triggering CI)
git commit --allow-empty -m "Empty commit"

# Sign commit with GPG
git commit -S -m "Signed commit"
```

### Removing and Moving Files
```bash
# Remove file from repository and filesystem
git rm <filename>

# Remove file from repository only (keep local)
git rm --cached <filename>

# Remove directory
git rm -r <directory>

# Move or rename file
git mv <old-name> <new-name>
```

### Ignoring Files
```bash
# Create .gitignore file
touch .gitignore

# Common .gitignore patterns
*.log           # Ignore all .log files
node_modules/   # Ignore node_modules directory
.env            # Ignore environment files
*.tmp           # Ignore temporary files
build/          # Ignore build directory
```

---

## Branching and Merging

### Branch Management
```bash
# List all local branches
git branch

# List all branches (local and remote)
git branch -a

# List remote branches
git branch -r

# Create new branch
git branch <branch-name>

# Create and switch to new branch
git checkout -b <branch-name>
git switch -c <branch-name>

# Switch to existing branch
git checkout <branch-name>
git switch <branch-name>

# Rename current branch
git branch -m <new-name>

# Rename specific branch
git branch -m <old-name> <new-name>

# Delete local branch
git branch -d <branch-name>

# Force delete local branch
git branch -D <branch-name>

# Delete remote branch
git push origin --delete <branch-name>

# Show branches with last commit
git branch -v

# Show merged branches
git branch --merged

# Show unmerged branches
git branch --no-merged
```

### Merging
```bash
# Merge branch into current branch
git merge <branch-name>

# Merge with no-fast-forward
git merge --no-ff <branch-name>

# Merge and squash commits
git merge --squash <branch-name>

# Abort merge
git merge --abort

# Continue merge after resolving conflicts
git merge --continue
```

### Rebasing
```bash
# Rebase current branch onto another
git rebase <branch-name>

# Interactive rebase
git rebase -i HEAD~<number-of-commits>

# Interactive rebase on branch
git rebase -i <branch-name>

# Continue rebase after resolving conflicts
git rebase --continue

# Skip current commit during rebase
git rebase --skip

# Abort rebase
git rebase --abort

# Rebase onto specific commit
git rebase --onto <new-base> <old-base> <branch>
```

---

## Remote Repositories

### Managing Remotes
```bash
# Add remote repository
git remote add <name> <url>

# Add origin remote
git remote add origin <url>

# Show remotes
git remote -v

# Show detailed remote info
git remote show <name>

# Rename remote
git remote rename <old-name> <new-name>

# Remove remote
git remote remove <name>

# Change remote URL
git remote set-url <name> <new-url>
```

### Fetching and Pulling
```bash
# Fetch from remote
git fetch

# Fetch from specific remote
git fetch <remote-name>

# Fetch specific branch
git fetch <remote-name> <branch-name>

# Fetch all remotes
git fetch --all

# Fetch and prune deleted branches
git fetch --prune

# Pull changes from remote
git pull

# Pull from specific remote and branch
git pull <remote-name> <branch-name>

# Pull with rebase
git pull --rebase

# Pull all remotes
git pull --all
```

### Pushing
```bash
# Push to remote
git push

# Push to specific remote and branch
git push <remote-name> <branch-name>

# Push and set upstream
git push -u origin <branch-name>
git push --set-upstream origin <branch-name>

# Push all branches
git push --all

# Push tags
git push --tags

# Force push (dangerous!)
git push --force

# Safer force push
git push --force-with-lease

# Delete remote branch
git push origin --delete <branch-name>
```

---

## Viewing History and Changes

### Log Commands
```bash
# View commit history
git log

# One line per commit
git log --oneline

# Show last n commits
git log -n 5

# Show commits with diff
git log -p

# Show commits with stats
git log --stat

# Graphical representation
git log --graph --oneline --all

# Pretty format
git log --pretty=format:"%h - %an, %ar : %s"

# Filter by author
git log --author="Name"

# Filter by date
git log --since="2 weeks ago"
git log --after="2023-01-01"
git log --before="2023-12-31"

# Filter by message
git log --grep="keyword"

# Show commits that modified a file
git log -- <filename>

# Show commits in a range
git log <branch1>..<branch2>

# Show merge commits
git log --merges

# Show non-merge commits
git log --no-merges
```

### Diff Commands
```bash
# Show unstaged changes
git diff

# Show staged changes
git diff --staged
git diff --cached

# Show changes between commits
git diff <commit1> <commit2>

# Show changes in specific file
git diff <filename>

# Show changes between branches
git diff <branch1>..<branch2>

# Show word-level diff
git diff --word-diff

# Show statistics only
git diff --stat

# Show changes with context
git diff -U10
```

### Show and Blame
```bash
# Show commit details
git show <commit-hash>

# Show file at specific commit
git show <commit-hash>:<filename>

# Show who changed each line
git blame <filename>

# Blame with line range
git blame -L 10,20 <filename>

# Blame with email
git blame -e <filename>
```

### Searching
```bash
# Search in working directory
git grep "search-term"

# Search in specific commit
git grep "search-term" <commit-hash>

# Search with line numbers
git grep -n "search-term"

# Search and show count
git grep -c "search-term"
```

---

## Undoing Changes

### Unstaging and Discarding
```bash
# Unstage file
git reset HEAD <filename>
git restore --staged <filename>

# Discard changes in working directory
git checkout -- <filename>
git restore <filename>

# Discard all local changes
git reset --hard HEAD

# Clean untracked files (dry run)
git clean -n

# Clean untracked files
git clean -f

# Clean untracked files and directories
git clean -fd
```

### Reset
```bash
# Soft reset (keep changes staged)
git reset --soft HEAD~1

# Mixed reset (keep changes unstaged) - default
git reset HEAD~1
git reset --mixed HEAD~1

# Hard reset (discard all changes)
git reset --hard HEAD~1

# Reset to specific commit
git reset --hard <commit-hash>

# Reset single file to specific commit
git reset <commit-hash> -- <filename>
```

### Revert
```bash
# Revert a commit (creates new commit)
git revert <commit-hash>

# Revert without committing
git revert -n <commit-hash>

# Revert a merge commit
git revert -m 1 <merge-commit-hash>

# Revert multiple commits
git revert <oldest-commit>..<newest-commit>
```

### Stash
```bash
# Stash current changes
git stash

# Stash with message
git stash save "message"

# Stash including untracked files
git stash -u

# Stash including ignored files
git stash -a

# List all stashes
git stash list

# Apply most recent stash
git stash apply

# Apply specific stash
git stash apply stash@{2}

# Apply and remove stash
git stash pop

# Remove specific stash
git stash drop stash@{0}

# Remove all stashes
git stash clear

# Show stash contents
git stash show

# Show stash diff
git stash show -p
```

---

## Advanced Git Features

### Cherry-picking
```bash
# Cherry-pick a commit
git cherry-pick <commit-hash>

# Cherry-pick multiple commits
git cherry-pick <commit1> <commit2>

# Cherry-pick without committing
git cherry-pick -n <commit-hash>

# Cherry-pick and edit message
git cherry-pick -e <commit-hash>

# Continue cherry-pick
git cherry-pick --continue

# Abort cherry-pick
git cherry-pick --abort
```

### Tags
```bash
# List all tags
git tag

# Create lightweight tag
git tag <tag-name>

# Create annotated tag
git tag -a <tag-name> -m "message"

# Tag specific commit
git tag <tag-name> <commit-hash>

# Show tag information
git show <tag-name>

# Delete local tag
git tag -d <tag-name>

# Delete remote tag
git push origin --delete <tag-name>

# Push tags to remote
git push --tags

# Push specific tag
git push origin <tag-name>

# Checkout tag
git checkout <tag-name>
```

### Submodules
```bash
# Add submodule
git submodule add <repository-url> <path>

# Initialize submodules
git submodule init

# Update submodules
git submodule update

# Update submodules recursively
git submodule update --init --recursive

# Update to latest commit
git submodule update --remote

# Show submodule status
git submodule status

# Execute command in each submodule
git submodule foreach <command>

# Remove submodule
git submodule deinit <path>
git rm <path>
```

### Bisect (Binary Search for Bugs)
```bash
# Start bisect
git bisect start

# Mark current commit as bad
git bisect bad

# Mark specific commit as good
git bisect good <commit-hash>

# Bisect will checkout middle commit for testing
# After testing, mark as good or bad
git bisect good  # or git bisect bad

# Bisect automatically with script
git bisect run <test-script>

# End bisect session
git bisect reset
```

### Worktrees
```bash
# Create new worktree
git worktree add <path> <branch>

# List worktrees
git worktree list

# Remove worktree
git worktree remove <path>

# Prune worktree information
git worktree prune
```

### Reflog
```bash
# Show reference log
git reflog

# Show reflog for specific branch
git reflog show <branch-name>

# Recover lost commit
git reflog
git checkout <commit-hash>
git branch <new-branch-name> <commit-hash>
```

### Hooks
```bash
# Hooks are located in .git/hooks/
# Common hooks:
# - pre-commit: runs before commit
# - pre-push: runs before push
# - post-commit: runs after commit
# - prepare-commit-msg: runs before commit message editor

# Make hook executable
chmod +x .git/hooks/pre-commit

# Example pre-commit hook:
#!/bin/sh
npm test
```

---

## GitHub-Specific Features

### Pull Requests (via CLI)
```bash
# View pull requests
gh pr list

# Create pull request
gh pr create

# Create PR with title and body
gh pr create --title "Title" --body "Description"

# View PR details
gh pr view <pr-number>

# Checkout PR locally
gh pr checkout <pr-number>

# Review PR
gh pr review <pr-number>

# Merge PR
gh pr merge <pr-number>

# Close PR
gh pr close <pr-number>

# Reopen PR
gh pr reopen <pr-number>
```

### Issues
```bash
# List issues
gh issue list

# Create issue
gh issue create

# Create issue with title and body
gh issue create --title "Title" --body "Description"

# View issue
gh issue view <issue-number>

# Close issue
gh issue close <issue-number>

# Reopen issue
gh issue reopen <issue-number>

# Add labels
gh issue edit <issue-number> --add-label "bug,enhancement"

# Assign issue
gh issue edit <issue-number> --add-assignee "username"
```

### GitHub Actions
```bash
# List workflows
gh workflow list

# View workflow runs
gh run list

# View specific run
gh run view <run-id>

# Watch run
gh run watch <run-id>

# Download artifacts
gh run download <run-id>

# Trigger workflow
gh workflow run <workflow-name>
```

### Releases
```bash
# List releases
gh release list

# Create release
gh release create <tag>

# Create release with files
gh release create <tag> <file1> <file2>

# View release
gh release view <tag>

# Download release assets
gh release download <tag>

# Delete release
gh release delete <tag>
```

### Gists
```bash
# Create gist
gh gist create <file>

# List gists
gh gist list

# View gist
gh gist view <gist-id>

# Edit gist
gh gist edit <gist-id>

# Delete gist
gh gist delete <gist-id>
```

### Repository Management
```bash
# Clone repository
gh repo clone <owner>/<repo>

# Create repository
gh repo create <name>

# Fork repository
gh repo fork <owner>/<repo>

# View repository
gh repo view

# List repositories
gh repo list <owner>

# Archive repository
gh repo archive <owner>/<repo>
```

---

## GitHub CLI (gh)

### Authentication
```bash
# Login to GitHub
gh auth login

# Check authentication status
gh auth status

# Logout
gh auth logout

# Refresh authentication
gh auth refresh

# Setup git credential helper
gh auth setup-git
```

### Browse
```bash
# Open repository in browser
gh browse

# Open specific file
gh browse <file>

# Open specific commit
gh browse <commit-hash>

# Open issues page
gh browse -- issues

# Open pull requests page
gh browse -- pulls
```

### Search
```bash
# Search repositories
gh search repos <query>

# Search issues
gh search issues <query>

# Search pull requests
gh search prs <query>

# Search code
gh search code <query>
```

---

## Collaboration Workflows

### Forking Workflow
```bash
# 1. Fork repository on GitHub
gh repo fork <owner>/<repo>

# 2. Clone your fork
git clone <your-fork-url>

# 3. Add upstream remote
git remote add upstream <original-repo-url>

# 4. Create feature branch
git checkout -b feature-branch

# 5. Make changes and commit
git add .
git commit -m "Add feature"

# 6. Push to your fork
git push origin feature-branch

# 7. Create pull request
gh pr create

# 8. Sync with upstream
git fetch upstream
git checkout main
git merge upstream/main
git push origin main
```

### Feature Branch Workflow
```bash
# 1. Update main branch
git checkout main
git pull origin main

# 2. Create feature branch
git checkout -b feature-name

# 3. Make changes and commit
git add .
git commit -m "Implement feature"

# 4. Push feature branch
git push -u origin feature-name

# 5. Create pull request
gh pr create

# 6. After review, merge to main
git checkout main
git merge feature-name
git push origin main

# 7. Delete feature branch
git branch -d feature-name
git push origin --delete feature-name
```

### Gitflow Workflow
```bash
# Main branches: main (production), develop (integration)

# Start new feature
git checkout develop
git checkout -b feature/feature-name

# Finish feature
git checkout develop
git merge --no-ff feature/feature-name
git branch -d feature/feature-name

# Start release
git checkout develop
git checkout -b release/1.0.0

# Finish release
git checkout main
git merge --no-ff release/1.0.0
git tag -a 1.0.0
git checkout develop
git merge --no-ff release/1.0.0
git branch -d release/1.0.0

# Hotfix
git checkout main
git checkout -b hotfix/1.0.1
# Make fixes
git checkout main
git merge --no-ff hotfix/1.0.1
git tag -a 1.0.1
git checkout develop
git merge --no-ff hotfix/1.0.1
git branch -d hotfix/1.0.1
```

---

## Best Practices

### Commit Messages
```bash
# Good commit message format:
# <type>: <subject>
#
# <body>
#
# <footer>

# Types:
# feat: New feature
# fix: Bug fix
# docs: Documentation changes
# style: Code style changes (formatting)
# refactor: Code refactoring
# test: Adding or updating tests
# chore: Maintenance tasks

# Example:
git commit -m "feat: add user authentication

Implemented JWT-based authentication system with login and signup endpoints.

Closes #123"
```

### Branch Naming
```bash
# Feature branches
feature/user-authentication
feature/add-payment-gateway

# Bug fix branches
bugfix/fix-login-error
fix/header-alignment

# Hotfix branches
hotfix/critical-security-patch

# Release branches
release/v1.2.0
```

### .gitignore Best Practices
```bash
# Operating System files
.DS_Store
Thumbs.db
*.swp

# IDE files
.vscode/
.idea/
*.sublime-project

# Dependencies
node_modules/
vendor/
packages/

# Build outputs
dist/
build/
*.o
*.exe

# Environment files
.env
.env.local
.env.*.local

# Logs
*.log
logs/

# Temporary files
*.tmp
temp/
```

### Security Best Practices
```bash
# Never commit sensitive data
# Use environment variables
# Check before committing:
git diff --cached

# If you accidentally committed secrets:
# 1. Remove from history
git filter-branch --force --index-filter \
  "git rm --cached --ignore-unmatch <file-with-secrets>" \
  --prune-empty --tag-name-filter cat -- --all

# 2. Force push
git push --force --all

# 3. Rotate the exposed secrets immediately

# Use git-secrets to prevent committing secrets
git secrets --install
git secrets --register-aws
```

### Performance Tips
```bash
# Shallow clone for faster cloning
git clone --depth 1 <url>

# Sparse checkout (clone only specific directories)
git clone --filter=blob:none --sparse <url>
git sparse-checkout init --cone
git sparse-checkout set <directory>

# Use git gc to optimize repository
git gc --aggressive

# Prune old references
git prune

# Clean up branches
git fetch --prune
git branch --merged | grep -v "\*" | xargs -n 1 git branch -d
```

---

## Additional Resources

### Useful Aliases
Add these to your `.gitconfig`:
```bash
[alias]
    # Short status
    s = status -s
    
    # Pretty log
    lg = log --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit
    
    # Show last commit
    last = log -1 HEAD --stat
    
    # Undo last commit
    undo = reset --soft HEAD^
    
    # Amend commit
    amend = commit --amend --no-edit
    
    # List branches sorted by last modified
    branches = branch --sort=-committerdate
    
    # Show contributors
    contributors = shortlog --summary --numbered
    
    # Find commits by message
    find = log --all --oneline --grep
```

### Common Scenarios

#### Recover Deleted Branch
```bash
git reflog
git checkout -b <branch-name> <commit-hash>
```

#### Split Large Commit
```bash
git reset HEAD~1
git add -p
git commit -m "First part"
git commit -am "Second part"
```

#### Change Commit Author
```bash
git commit --amend --author="New Name <email@example.com>"
```

#### Remove File from All History
```bash
git filter-branch --tree-filter 'rm -f <filename>' HEAD
```

#### Squash All Commits
```bash
git reset --soft $(git rev-list --max-parents=0 HEAD)
git commit --amend -m "Initial commit"
```

---

## Conclusion

This guide covers the essential Git and GitHub commands and features. Practice these commands regularly to become proficient with version control and collaboration workflows.

For more information, visit:
- [Git Documentation](https://git-scm.com/doc)
- [GitHub Docs](https://docs.github.com)
- [GitHub CLI Manual](https://cli.github.com/manual/)

Happy coding! 🚀