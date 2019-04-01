# 3081 HW00 GitHub Basics

## What You Will Learn
1. Basic Linux commands, for example _mkdir_, _cd_, _mv_, and _ls_.
1. How to configure github for your cselabs account.
2. How to _clone_ (create a local copy of an existing repo), _pull_ (get
   updates), and _push_ (make updates).
3. How to configure the _.gitignore_ file so that _push_ ignores files not
   necessary to track.
4. The required directory structure and file nomenclature for course
   assignments.
5. How to initiate and read automated testing of course assignments.

_For additional information about Linux, see
https://www-users.cs.umn.edu/~larson/repo-website-resources/website/examples/csresources/linux.html

### Configuring GitHub

Below, a number of commands are shown that should be typed into the command
line. These are preceded by a percent sign "%" which is NOT to be typed in.

Log into your cselabs account.

    % git --version

This will establish if it is installed.

    % git config --global user.name "Your Name"
    % git config --global user.email your_email@umn.edu

In order to use git, it has to know what to call you in its history. These commands set the configuration to know what identification to use. Note that your name appears between double quotes since it has spaces in it. Your email address doesn't, so it doesn't need to be in quotes. [Note: If you use git for other accounts than your UMN account, you can remove the global tag (_--global_) to set the name and email for only this repository, but you must be within a git repo to do so.]

#### [OPTIONAL]

    % git config --global core.editor "your editor choice here"

If you would like `emacs -nw` as your editor (emacs such that it doesn't open a new window
but opens in the terminal) then you'll want double quotes around that 2 word
phrase. Also note that if you want to use gedit, you probably need to use `gedit
-w -s`. Also also note that you should probably *not* use `atom`, because it has
its own git plugin that does not usually play nice with command line git.

Use

    % git config --list

to see that git has set this up correctly.

### csci3081-shared-upstream: the Read-Only 3081 Course Repository

Computer Science courses are setup for github by first establishing a GitHub
organization (e.g. _umn-csci-3081-F18_), as well as a read-only course repository
(e.g. _csci3081-shared-upstream_). Course materials will be distributed via the
read-only repository.

Open your browser and enter the following URL:

https://github.umn.edu/umn-csci-3081-F18/csci3081-shared-upstream

By default, you will be shown the default branch. In this case, that is the support-code branch. This branch will contain all of the material files which are necessary to complete the homework and, eventually, the project.

> It's important to note that _support-code_ is not the typical default branch.
> New repos are almost always created with a branch called _master_. This is the
> common name for the default branch in Github. We've changed that because of how
> we intend to make use of the master branch during the project.

Take some time and poke around in this repository, especially if you have never seen the GitHub interface before. If you have questions about the interface, ask StackOverflow or the almighty Google. If you have questions about the contents, ask a TA or on the forums.

### Creating your personal repository.

This can be done in two ways. If you'd like to create the repository on your own in command line, you are free to do so. The TAs may be able to help. These instructions will show the steps for the other method: creating the repository through the Github interface.

Navigate to the umn-csci-3081-F18 (https://github.umn.edu/orgs/umn-csci-3081-F18) organization page. If you are still in the csci3081-shared-upstream repository, you can click on the organization name at the top of the page, just under the black header bar. Otherwise, you'll find it in your profile (click on the icon on the top right and select _Your Profile_).

The green button on the right says 'New'. Click on it. Here you'll create a new repository with your name.

Under repository name, you must follow the following convention for the grading scripts to properly identify and grade your work: repo-&lt;student-umnid&gt;. For example, if your UMN id is doexx123, then your repository should be named repo-doexx123.

Next, ensure that you select _private_ as the privacy setting. If you leave it as public, any other student can also see your repository (and potentially push code, delete code, etc.).

Select the checkbox to 'Initialize this repository with a README'. There's no need to add any .gitignore details.

When you select 'Create repository', your personal repository will be created on the Github.umn.edu server. Next, we'll clone this remote repository into a local repository, where you can do your work. We strongly recommend that you do **NOT** follow the instructions listed in this new repo. What we'll be doing is slightly different than how the typical repository would be built.

Under 'Clone or Downlaod', ensure that HTTPS is selected and click on the copy icon on the far right. This will copy the repository reference to the clipboard. Now, we can clone this repo from our remote Github instance to your local workspace (on the CSELabs machine).

### Cloning your personal repository

Go back to your terminal. At the top level of your cselabs account or within a subdirectory of your choice,
create a 3081 directory with any name you prefer, then move to that
directory. You will now clone your individual repo into this
directory. Replace (i.e. paste, typically Shift+Insert in a terminal) **_&lt;clone-ref&gt;_** with the repository reference we copied earlier.

    % (optional) cd <location of your choosing>
    % mkdir 3081_F18
    % cd 3081_F18
    % git clone <clone-ref>
    % ls

**_What just happened?_** You made a new directory (i.e. folder) in your account
with `mkdir`. You changed that to your working directory with `cd`. You copied
the repo locally to your machine with `clone`. You listed the contents of
the working directory with `ls`, which should list the newly created directory
with the name of the repository which it contains. These directories function
exactly like all other linux directories. There are hidden files that track
changes to the repository.

### Connecting to GitHub with SSH
Notice how you were prompted to enter your email id and password when you cloned
the shared-upstream repo.

One way to avoid entering your email id and password every time you access your
remote repository is to set up an SSH key for your CSE labs account.

This can be done by following the instructions listed on this page -
https://help.github.com/enterprise/2.12/user/articles/generating-an-ssh-key/

You will then need to add the key to your github profile from the documentation (https://help.github.com/enterprise/2.12/user/articles/adding-a-new-ssh-key-to-your-github-account/).  Unfortunately xclip is not installed on the lab machines, so you can copy the results from the command line after typing out the public key as follows:

    % cat ~/.ssh/id_rsa.pub

Now that you have an SSH key set up, you need to change the repository's remote
URL from HTTPS to SSH. Again, replace **_&lt;student-umnid&gt;_** with your UMN id and **_&lt;clone-ref&gt;_** with the repository reference we copied earlier.

    % cd repo-<student-umnid>
    % git remote set-url origin <clone-ref>
    % cd ..

NOTE: The SSH key you generated is only for your CSE labs account. When working
on your personal machine, you will have to generate another SSH key for that
machine. Cloning a repository with SSH is possible only when you have an SSH key
linked to your account for that machine.





### Setting a second remote: Getting the support-code

What we want to be able to do, as instructors, is to publish code and other materials to aid you in your work throughout the semester. To do that most efficiently, and give you some Git practice along the way, we will be publishing updates to the csci3081-shared-upstream repository. The next step then is getting those changes and materials into your own repository.

What we'll do is add a second remote target to your local repository. This means that you can pull from two different repositories into your local repo (note: you can only push to your own remote repo; we'll prevent you from pushing to the shared-upstream).

From your own repository's directory, apply the following commands. Again, replace &lt;student-umnid&gt; with your UMN id and &lt;clone-ref&gt; with the repository reference we copied earlier.

    % cd repo-<student-umnid>

The next command is condition, depending on whether or not you configured an SSH KEY for your account.
If you completed the ssh key section above:

    % git remote add upstream git@github.umn.edu:umn-csci-3081-F18/csci3081-shared-upstream.git

If you did not complete the ssh key section above and are using username/password:

    % git remote add upstream https://github.umn.edu/umn-csci-3081-F18/csci3081-shared-upstream.git

* Note: If you get an error saying that the remote already exists, you can remove it and add again with the following command:

		% git remote rm upstream


In either case, apply this command next.

    % git remote -v

**_What just happened?_** After entering your local repository, you added a remote target to the local repository. This will allow you to pull _support-code_ from the shared-upstream repository. Then, to verify it worked, you listed the remote targets that are currently available. You should see two sets of two: a fetch and push for origin (your repo) and a fetch and push for the shared-upstream repo.

Now, let's add the _support-code_ branch to our local repository before getting what we need from shared-upstream.

    % git checkout -b support-code
	
**_What just happened?_** You did two things at once. First, you created a new local branch, called support-code. Second, you switch the branch you are in to the support-code branch. We'll show the difference in a moment.

Now, get the student support code for Homework 0 by _pulling_ from the _support-code_ branch of the shared-upstream repository.

    % git pull upstream support-code --allow-unrelated-histories
	% ls

**_What just happened?_** You downloaded the contents of the shared-upstream branch into your local support-code branch. Listing the contents of the current directory now shows the existence of the HW/ directory. Within that directory is HW00/ and within that subdirectory are the files main.cpp, makefile, and README.md (which is the same file you're reading right now, just now there's a copy on your machine).

We're now in the support-code branch. Branches are useful for keeping _sets_ or _versions_ of your codebase separate. This is commonly used to separate good, clean working production code (_master_) from development versions (_develop_) and versions that individual developers are working on to fix a bug or add a feature (e.g., _bug_34_typos_everywhere). 

You can see the different by switching between the different branches, using the git checkout &gt;branch_name&lt; command.

    % git checkout master
	% ls
	
Now, the file system represents the contents of the master branch, which we have not modified yet. Note that HW/ does not exist.

    % git checkout support-code
	% ls
	
See that HW/ again exists. We'll be using these branches to our advantage in later homework and the project. Return once more to the _master_ branch before continuing.

    % git checkout master

### Merging support-code into your official work branch

When submitting your work, you'll be using the _master_ branch. We'll get more sophisticated with how and where you're do work later, but for now, _master_ branch is where it's at.

    % git merge support-code
	% git status
	
**_What just happened?_** You merged the file contents and commit history from _support-code_ to _master_. You can see that you are now ahead of _origin/master_ (i.e., the _master_ branch on your remote repo on Github) by several commits. We'll make some more before following git's advice and pushing our local commits.
	

### Executing Homework Code and Pushing Results

The code provided for HW00 will create an executable by compiling the provided
C++ files using a _makefile_. Running the executable will generate 2 files that
will be added to your HW00 directory. A _makefile_ manages the compilation
process, which will be explored further in later homework, so don't worry about
the contents of the file right now.

    % cd HW/HW00
    % make
    % ls

**_What just happened?_** You made _HW00_ your working directory with `cd`. You
executed the makefile (named _makefile_) with `make`, which created object files
with the extension _.o_, and the executable _HW00.out_. These files are
displayed with `ls`.

    % ./HW00.out
    % ls

**_What just happened?_** You ran the executable with `./HW00.out`, which
generated 2 files _private.pvt_ and _shared.md_. 

In the next part of this homework, you will setup the _.gitignore_ file so that the former file is not added to the repo, but the latter is.

Before telling git what not to track, look at what it has been tracking.

    % git status

You will see the directories and files that have been added to this repository.

### Configuring and Using _.gitignore_

There are a lot of files that should not be tracked in the repository. You
typically don't want object and executable files included in your repo, because
these are consequences of the local compilation. There are common files or
libraries that should not be included, because:

1. It is wasteful to have multiple copies and to spend bandwidth moving them
   around.
2. There might also be files that are for you only, such as notes about the
   project or todo lists.

3. Such files may *ONLY* be capable of running on the machine that you are
   currently on, and if you move to another machine and try to run them you
   might get very strange errors/behavior. Better to avoid this altogether.

The _.gitignore_ file stores file extensions that serve as a filter for git. Any
file with that extension will not be tracked.

*HOWEVER*, if you add a file to a _.gitignore_ and that file is already checked
into your repo, changes to the _.gitignore_ to ignore that file have no effect;
it only applies to FUTURE checkins to the repository.

If you are still in the HW00 directory, using your favorite text editor, create a
.gitignore file, e.g. `xemacs .gitignore &`, which will open xemacs in a new
window. Edit the .gitignore file to remove your executable.

Add these lines to the file:

    # Extensions to not include in repo
    *.o
    *.out
    *.pvt

Save the file.

**_What just happened?_** You added a comment by prefacing the first line with
`#`. You indicated to not track any and all files with the use of `*` that has a
specific file extension (e.g. `*.o`). If you have a one-off, you can include
that specific file. You can also add a directory name, which will ignore all
contents of the directory.

Look at the results:

    % git status

Now you will see that the indicated files in _.gitignore_ are no longer
considered to be untracked, and are simply ignored.

### Add Changes to Repo both Locally and on the Server

You need to _stage_ all changes to the repository, which prepares those items to
be permanently part of the repository. When you _commit_ those changes, they are
saved to your local repository, which lives in your cselabs account (or your
personal computer if that is what you are working on). When you _push_ those
changes, they will be copied to the repo on the server. The difference between
_commit_ and _push_ is what separates git from centralized version control
systems.

    % git add -A
    % git commit -m "add(HW00): Adding HW00 results."
    % git push

**_What just happened?_** All of the tracked changes were staged with `git add
-A`. You could have only staged certain files by replacing _-A_ with the
filename. Note that `add` does not mean you are adding a new file or a new
directory, it means you are adding a change (any change). Those staged changes
were committed to your local repository and tagged with the message that follows
`-m`, then pushed to the server.

>Always use good comments in the commit. If you need to restore a previous state
>of the repo that is several commits back, you will have a much easier time
>figuring out which commit is relevant when you use comments like _"adding robot
>class definition"_, as opposed to _"more class stuff"_.

>Always verify that the changes have been uploaded to the server by looking at
>the repo through the web interface of github.

### Reading the Feedback

Pushing to the server triggers the automated grading system. Soon your repo will
contain a feedback file, letting you know if you have passed all tests of the
assignment. These tests will make sure you have the right directory structure,
filenames, and that everything is behaving as indicated in the requirements.

Watch your github account via the web interface to see when the feedback file is
ready (hit refresh to check contents). You can look at it through the web, but
it is important to pull in that file to your local repo, so as not to cause
merge conflicts.

    % git pull
    % cd HW/HW00
    % ls

> ALWAYS, ALWAYS, ALWAYS perform a _pull_ before making changes to a
> repository. Each time you sit down to work on a homework or project iteration, it
> would be an excellent habit to perform a _pull_ of the support code.

THIS HOMEWORK IS COMPLETE.

Congratulations!
