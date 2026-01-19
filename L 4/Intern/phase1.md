Repository add & configure Git username & email
git status #To check current status of repository
git init #To initialize the repository if not initialized yet
কোন Git রিপোজিটরিতে আছেন কি না বা আপনার বর্তমান ফোল্ডারটি একটি Git রিপোজিটরি কি না, তা চেক করার কয়েকটি সহজ উপায় আছে:

১. সবথেকে সহজ উপায়: git status
আপনার টার্মিনালে শুধু নিচের কমান্ডটি লিখুন:

Bash -> git status
যদি এটি রিপোজিটরি হয়: আপনি দেখতে পাবেন কোন ব্রাঞ্চে (Branch) আছেন এবং আপনার ফাইলগুলোর অবস্থা কী। (যেমন: On branch main)

যদি এটি রিপোজিটরি না হয়: টার্মিনালে এই এরর মেসেজটি আসবে:
fatal: not a git repository (or any of the parent directories): .git
২. হিডেন ফোল্ডার চেক করা (ম্যানুয়ালি)
প্রতিটি Git রিপোজিটরির ভেতরে একটি হিডেন (Hidden) ফোল্ডার থাকে যার নাম .git। আপনি টার্মিনাল থেকে এটি দেখতে এই কমান্ডটি দিতে পারেন:

Git Bash বা Linux-এ: ls -a
Windows CMD-তে: dir /ah

যদি লিস্টে .git ফোল্ডারটি দেখেন, তবে বুঝবেন এটি একটি লোকাল রিপোজিটরি।

৩. রিমোট লিঙ্ক চেক করা (কোন GitHub লিঙ্কের সাথে যুক্ত)
আপনি যদি দেখতে চান এই ফোল্ডারটি GitHub-এর কোন নির্দিষ্ট রিপোজিটরির সাথে কানেক্ট করা আছে, তবে লিখুন:
Bash -> git remote -v

যদি এটি কোনো অনলাইন রিপোজিটরির সাথে যুক্ত থাকে, তবে তার URL (লিঙ্ক) এখানে দেখাবে। যদি কিছুই না দেখায়, তার মানে এটি শুধুমাত্র আপনার পিসিতেই আছে, অনলাইনে লিঙ্ক করা নেই।

## repository link add করা

১. লিঙ্কটি কোথায় পাবেন?
প্রথমে GitHub-এ গিয়ে একটি নতুন রিপোজিটরি (New Repository) তৈরি করুন। তৈরি করার পর সেখানে HTTPS বা SSH ট্যাব থেকে একটি লিঙ্ক পাবেন, যা দেখতে অনেকটা এরকম: https://github.com/your-username/your-repo-name.git

২. লোকাল প্রজেক্টের সাথে লিঙ্ক করার নিয়ম
আপনার টার্মিনালে প্রজেক্ট ফোল্ডারের ভেতর থেকে নিচের ধাপগুলো ফলো করুন:
গিট শুরু করা (যদি আগে না করে থাকেন):

Bash -> git init
GitHub-এর লিঙ্কটি সেট করা (এটিই আসল কাজ):

Bash -> git remote add origin https://github.com/your-username/your-repo-name.git
(এখানে origin হলো আপনার অনলাইনের লিঙ্কটির একটি সংক্ষিপ্ত নাম)

৩. লিঙ্ক হয়েছে কি না চেক করা
আপনার লোকাল প্রজেক্টটি কোন লিঙ্কের সাথে কানেক্টেড আছে তা দেখতে এই কমান্ডটি দিন:

Bash -> git remote -v
যদি সবকিছু ঠিক থাকে, তবে আপনি আপনার GitHub রিপোজিটরির লিঙ্কটি দেখতে পাবেন।

## নতুন ব্রাঞ্চে কোড আপলোড (Push) করা

কখনো কখনো প্রয়োজন হয় নতুন একটি ব্রাঞ্চ (Branch) তৈরি করে সেখানে কোড আপলোড (Push) করার। নিচে ধাপে ধাপে সেই প্রক্রিয়া দেওয়া হলো:

১. নতুন ব্রাঞ্চ তৈরি করা এবং সেখানে যাওয়া
টার্মিনালে এই কমান্ডটি দিন (এখানে apnar-branch-name এর জায়গায় আপনার পছন্দমতো নাম দিন):

Bash -> git checkout -b apnar-branch-name
(এই কমান্ডটি একই সাথে একটি নতুন ব্রাঞ্চ তৈরি করবে এবং আপনাকে সেই ব্রাঞ্চে নিয়ে যাবে)

২. ফাইলগুলো অ্যাড করা
আপনার করা পরিবর্তনগুলো স্টেজিং এরিয়াতে যোগ করুন:

Bash

git add .
৩. পরিবর্তনগুলো কমিট করা
Bash -> git commit -m "apnar commit message"
৪. নতুন ব্রাঞ্চটি GitHub-এ পাঠানো (Push)
এখন কোডগুলো ওই নির্দিষ্ট ব্রাঞ্চে পাঠাতে নিচের কমান্ডটি দিন:

Bash -> git push -u origin apnar-branch-name
(এখানে apnar-branch-name এর জায়গায় আপনার তৈরি করা ব্রাঞ্চের নাম দিন)

কিছু জরুরি তথ্য:
ব্রাঞ্চ চেক করা: আপনি বর্তমানে কোন ব্রাঞ্চে আছেন তা দেখতে git branch লিখুন। বর্তমানে যে ব্রাঞ্চে আছেন তার পাশে একটি স্টার (\*) চিহ্ন থাকবে।

অন্য ব্রাঞ্চে যাওয়া: যদি আগে থেকে তৈরি কোনো ব্রাঞ্চে যেতে চান, তবে লিখুন: git checkout branch-name (এখানে -b লাগবে না)।
এখন GitHub-এ গিয়ে আপনার রিপোজিটরি চেক করলে দেখবেন সেখানে দুটি ব্রাঞ্চ আছে (main এবং আপনার তৈরি করা নতুনটি)।

যদি লিঙ্ক ভুল হয় বা পরিবর্তন করতে চান?
যদি দেখেন ভুল রিপোজিটরির সাথে লিঙ্ক করে ফেলেছেন, তবে এই কমান্ড দিয়ে লিঙ্কটি আপডেট করতে পারেন:

Bash -> git remote set-url origin https://github.com/your-username/new-repo-name.git

## git pull request

Pull Request (PR) হলো এমন একটি প্রক্রিয়া যার মাধ্যমে আপনি অন্যদের (বা মেইন প্রোজেক্টের মালিককে) জানান যে—আপনি কিছু পরিবর্তন করেছেন এবং আপনি চান সেই পরিবর্তনগুলো মেইন কোড বা main ব্রাঞ্চের সাথে যুক্ত (Merge) করা হোক।

আপনি যেহেতু নতুন ব্রাঞ্চে কোড পুশ করেছেন, এখন আপনি নিচের ২টি উপায়ে PR করতে পারেন:

পদ্ধতি ১: GitHub ওয়েবসাইট থেকে (সবচেয়ে সহজ)
১. আপনার GitHub রিপোজিটরিতে যান। ২. সেখানে একটি হলুদ রঙের ব্যানার দেখতে পাবেন যাতে লেখা আছে: "Compare & pull request"। ওই বাটনে ক্লিক করুন। ৩. এরপর একটি পেজ আসবে যেখানে:

base: main (যেখানে কোড যাবে)

compare: your-branch-name (যেখান থেকে কোড আসবে) ৪. একটি সুন্দর টাইটেল এবং আপনি কী কাজ করেছেন তার একটি ছোট বর্ণনা (Description) লিখুন। ৫. সবশেষে "Create pull request" বাটনে ক্লিক করুন।

পদ্ধতি ২: টার্মিনাল থেকে (GitHub CLI ব্যবহার করে)
আপনি যদি আগে GitHub CLI (gh) ইন্সটল করে থাকেন, তবে ব্রাউজারে না গিয়েই টার্মিনাল থেকে PR করতে পারেন:

১. টার্মিনালে লিখুন:

Bash

gh pr create --title "আপনার কাজের টাইটেল" --body "কাজের বর্ণনা"
২. এরপর কিছু অপশন আসতে পারে, সেখানে এন্টার চাপলে আপনার PR তৈরি হয়ে যাবে।

এর পরের কাজ কী?
PR তৈরি করার পর সাধারণত ৩টি জিনিস ঘটে:
Review: কেউ আপনার কোড চেক করে দেখবে কোনো ভুল আছে কি না।
Conflict Check: GitHub নিজে চেক করবে আপনার কোড মেইন ব্রাঞ্চের সাথে কোনো ঝামেলা করছে কি না।
Merge: সবকিছু ঠিক থাকলে আপনি নিজেই (বা অ্যাডমিন) "Merge pull request" বাটনে ক্লিক করে কোডগুলো main ব্রাঞ্চে ঢুকিয়ে দেবেন।

বোনাস টিপস:
আপনার কাজ শেষ হয়ে গেলে এবং কোড main-এ চলে গেলে, আপনি চাইলে আপনার তৈরি করা এক্সট্রা ব্রাঞ্চটি ডিলিট করে দিতে পারেন।

## ব্রাঞ্চ ডিলিট করার প্রক্রিয়াটি দুইভাবে করতে হয়—একটি আপনার নিজের পিসি (Local) থেকে এবং অন্যটি GitHub (Remote) থেকে। নিচে সহজ কমান্ডগুলো দেওয়া হলো:

১. লোকাল পিসি (Local) থেকে ব্রাঞ্চ ডিলিট করা
প্রথমে নিশ্চিত হয়ে নিন যে আপনি বর্তমানে সেই ব্রাঞ্চটিতে নেই যা আপনি ডিলিট করতে চান। অন্য কোনো ব্রাঞ্চে (যেমন: main) চলে যান:

Bash -> git checkout main
এখন নিচের কমান্ডটি দিন:

মার্জ করা হয়ে থাকলে (নিরাপদ উপায়):

Bash -> git branch -d branch-name
মার্জ না করলেও জোরপূর্বক ডিলিট করতে চাইলে:

Bash -> git branch -D branch-name
২. GitHub (Remote) থেকে ব্রাঞ্চ ডিলিট করা
GitHub সার্ভার থেকে ব্রাঞ্চটি মুছে ফেলতে টার্মিনালে এই কমান্ডটি দিন:

Bash -> git push origin --delete branch-name
৩. GitHub ওয়েবসাইট থেকে ডিলিট করা (বিকল্প উপায়)
আপনি চাইলে সরাসরি GitHub-এর ওয়েবসাইট থেকেও এটি করতে পারেন:

আপনার রিপোজিটরিতে যান।

"Branches" অপশনে ক্লিক করুন (যেখানে ব্রাঞ্চের সংখ্যা দেখায়)।

আপনার ব্রাঞ্চের নামের পাশে একটি ডাস্টবিন (Trash) আইকন দেখতে পাবেন, সেখানে ক্লিক করলেই ডিলিট হয়ে যাবে।

ডিলিট হয়েছে কি না চেক করার কমান্ড:
লোকাল ব্রাঞ্চ চেক করতে: git branch

রিমোট ব্রাঞ্চ চেক করতে: git branch -a

টিপস: কাজ শেষ হয়ে যাওয়ার পর ব্রাঞ্চ ডিলিট করে ফেলা ভালো, এতে রিপোজিটরি পরিষ্কার থাকে।

## Merge হয়েছে কি না এবং Pull Request (PR) সাকসেসফুল হয়েছে কি না, তা বোঝার সবচেয়ে সহজ উপায় হলো GitHub-এর ওয়েবসাইট চেক করা। তবে টার্মিনাল থেকেও এটি চেক করা যায়।

নিচে বিস্তারিত পদ্ধতি দেওয়া হলো:

১. GitHub ওয়েবসাইট দেখে বোঝা (সহজ উপায়)
আপনার GitHub রিপোজিটরির "Pull requests" ট্যাবে যান:

Open: যদি দেখেন আপনার PR-টি এখনো "Open" ট্যাবে আছে, তার মানে এটি এখনো Merge হয়নি।
Merged: যদি PR-এর পাশে বেগুনি রঙের (Purple) একটি আইকন এবং "Merged" লেখা দেখেন, তার মানে আপনার কাজ সফলভাবে main ব্রাঞ্চে ঢুকে গেছে।
Closed: যদি লাল রঙের "Closed" লেখা দেখেন, তার মানে PR-টি গ্রহণ না করেই বন্ধ করে দেওয়া হয়েছে।

২. টার্মিনাল (Git CLI) ব্যবহার করে চেক করা
আপনার পিসিতে টার্মিনাল ওপেন করে নিচের ধাপগুলো ফলো করুন:

প্রথমে main ব্রাঞ্চে যান:

Bash -> git checkout main
GitHub থেকে সব আপডেট নিয়ে আসুন:
Bash -> git pull origin main
এখন চেক করুন আপনার ব্রাঞ্চটি মার্জ হয়েছে কি না:

Bash -> git branch --merged
(এই লিস্টে যদি আপনার নতুন তৈরি করা ব্রাঞ্চটির নাম দেখতে পান, তবে বুঝবেন সেটি সফলভাবে main-এর সাথে মার্জ হয়ে গেছে।)

৩. GitHub CLI (gh) ব্যবহার করে চেক করা
যদি আপনি GitHub CLI ব্যবহার করেন, তবে খুব সহজেই স্ট্যাটাস দেখতে পারেন:

Bash -> gh pr status
এই কমান্ডটি দিলে আপনার করা সাম্প্রতিক PR-এর অবস্থা (Open, Merged, or Closed) সরাসরি টার্মিনালেই দেখিয়ে দেবে।

৪. কোড চেক করে নিশ্চিত হওয়া
আপনি সরাসরি main ব্রাঞ্চের ফাইলগুলো ওপেন করে দেখতে পারেন আপনার করা পরিবর্তনগুলো সেখানে আছে কি না। যদি কোডগুলো দেখতে পান, তবে বুঝবেন মার্জ হয়ে গেছে।

সংক্ষেপে চেনার উপায়:

সবুজ রঙ (Open): কাজ চলছে।

বেগুনি রঙ (Merged): অভিনন্দন! কাজ সফল।

লাল রঙ (Closed): ক্যানসেল করা হয়েছে।

আপনার কমান্ডগুলোর মানে:
cd ~: এটি আপনাকে আপনার পিসির Home Directory-তে (যেখানে Desktop, Documents ফোল্ডার থাকে) নিয়ে যাবে।
cd /d: এটি আপনাকে সরাসরি D Drive-এর একদম শুরুতে (Root) নিয়ে যাবে।
cd "L 4": এটি আপনাকে L 4 নামের ফোল্ডারে ঢুকিয়ে দেবে। নামের মাঝে স্পেস থাকলে এভাবে উদ্ধরণ চিহ্ন ("") দিতে হয়।
cd "../L 4/Intern":.. মানে এক ধাপ পেছনে যাওয়া।পুরোটার মানে: "এক ধাপ পেছনে যাও, তারপর সেখানে থাকা L 4 ফোল্ডারের ভেতর Intern ফোল্ডারে ঢোকো।"
cd ..: বর্তমানে যে ফোল্ডারে আছেন, সেখান থেকে ঠিক এক ধাপ পেছনে বা বাইরের ফোল্ডারে যাওয়ার জন্য এটি ব্যবহৃত হয়।
## আরও কিছু প্রয়োজনীয় টার্মিনাল কমান্ড

ls = বর্তমান ফোল্ডারে কী কী ফাইল বা ফোল্ডার আছে তার লিস্ট দেখা।
pwd = বর্তমানে আপনি ঠিক কোন ফোল্ডারের ভেতরে আছেন (পুরো পাথ) তা দেখা।
mkdir folder_name = নতুন একটি ফোল্ডার তৈরি করা।
touch file_name.txt = নতুন একটি ফাইল তৈরি করা।
clear = টার্মিনালের স্ক্রিন পরিষ্কার করা (অনেক লেখা হয়ে গেলে)।
mv file.txt folder/ = কোনো ফাইলকে এক জায়গা থেকে অন্য জায়গায় সরানো (Move)।
rm file.txt = কোনো ফাইল ডিলিট করা (সাবধানে ব্যবহার করবেন!)।
rm -rf folder_name = একটি পুরো ফোল্ডার এবং তার ভেতরের সব ডিলিট করা।

## Git username & email set করা

1.Global Git username & email set

    git config --global user.name "Sakif Shahrear"
    git config --global user.email "sakifshahrear@email.com"

## for chacking\*\*

    git config --global --list
    $ git config --global --list
    Output:
    user.email=sakifshahrear@gmail.com
    user.name=Sakif Shahrear
    filter.lfs.clean=git-lfs clean -- %f
    filter.lfs.smudge=git-lfs smudge -- %f
    filter.lfs.process=git-lfs filter-process
    filter.lfs.required=true

2. Local repository Git username & email set
    git config user.name "Sakif Shahrear"
    git config user.email "sakifshahrear@gmail.com"
## for chacking\*\*
    git config --list
    $ git config --list
    Output:
    $ git config --list
diff.astextplain.textconv=astextplain
filter.lfs.clean=git-lfs clean -- %f
filter.lfs.smudge=git-lfs smudge -- %f
filter.lfs.process=git-lfs filter-process
filter.lfs.required=true
http.sslbackend=openssl
http.sslcainfo=C:/Program Files/Git/mingw64/ssl/certs/ca-bundle.crt
core.autocrlf=true
core.fscache=true
core.symlinks=false
pull.rebase=false
credential.helper=manager
:  ->>  ** means there someting under which can't be shown here. for open terminal and type the command only q word. **
3. Global config থেকে একটি value remove করা

 email remove :

git config --global --unset user.email

# পুরো user section delete করা

git config --global --remove-section user

4. Make a small file change, stage it, view staged changes only.

staged command: git diff --staged (first git add korte hobe)
staged -> (state) which changes are added to the staging(state) area (git add) but not yet committed. (change ta git add kora hoyeche but git commit kora hoyni.)
আপনি যা নতুন যোগ করেছেন তা সবুজ রঙে (+) দেখাবে।

যা মুছে ফেলেছেন তা লাল রঙে (-) দেখাবে।

এটি শুধুমাত্র সেই পরিবর্তনগুলোই দেখাবে যেগুলো আপনি git add করেছেন কিন্তু এখনো commit করেননি।



    #include <bits/stdc++.h>
    using namespace std;
    +#define int long long

    -int main()
    +int32_t main()
    {
        int n;
        int x, y, z;
    @@ -9,10 +10,10 @@ int main() 
    @@ -9,10 +10,10 @@ int main()

        for (int i = 0; i < n; i++)
        {
    -        int x;
    +        int x, count=0;
    +        int y;
            cin >> x;

    -        int count = 0;
            for (int j = 1; j * j <= x; j++)
            {
                if (x % j == 0)
    (END)
    # @@ -0,0 +1,36 @@: এর মানে ফাইলটি আগে খালি ছিল, এখন আপনি নতুন ১ থেকে ৩৬ নম্বর লাইন পর্যন্ত কোড যোগ করেছেন।

    কমান্ড,কী দেখায়?
5. View all changes (staged + unstaged) compared to last commit.

git diff ==== শুধুমাত্র সেই পরিবর্তনগুলো যেগুলো এখনো git add করা হয়নি (Unstaged)।
git diff --staged ==== শুধুমাত্র সেই পরিবর্তনগুলো যেগুলো git add করা হয়েছে (Staged)।
git diff HEAD ==== সবকিছুই দেখায় (Staged + Unstaged)। অর্থাৎ লাস্ট কমিটের পর থেকে আপনি যত যা করেছেন।

User@LAPTOP-4MIGM0J8 MINGW64 /d/coding/L 4/Intern (sakif_shahrear)
$ git diff head
diff --git a/L 4/Intern/one.txt b/L 4/Intern/one.txt
index 3b0980f..f9f6be8 100644
--- a/L 4/Intern/one.txt
+++ b/L 4/Intern/one.txt
@@ -11,7 +11,8 @@ int32_t main()
     for (int i = 0; i < n; i++)
     {
         int x, count=0;
-        int y;
+        int y,m,n,o;
+        int change;
         cin >> x;

         for (int j = 1; j * j <= x; j++)
diff --git a/L 4/Intern/phrase.md b/L 4/Intern/phrase.md
index d7d5810..2a21fe3 100644
--- a/L 4/Intern/phrase.md
+++ b/L 4/Intern/phrase.md
@@ -244,15 +244,51 @@ core.fscache=true
 core.symlinks=false
 pull.rebase=false
 credential.helper=manager
-:
+:  ->>  ** means there someting under which can't be shown here. for open terminal and type the command
 only q word. **
 3. Global config থেকে একটি value remove করা

  email remove :

 git config --global --unset user.email

-4️. পুরো user section delete করা
+# পুরো user section delete করা

 git config --global --remove-section user

-5️.
\ No newline at end of file
+4. Make a small file change, stage it, view staged changes only.
+
+staged command: git diff --staged (first git add korte hobe)
+staged -> (state) which changes are added to the staging(state) area (git add) but not yet committed. (change ta git add kora hoyeche but git commit kora hoyni.)
+আপনি যা নতুন যোগ করেছেন তা সবুজ রঙে (+) দেখাবে।
+
+যা মুছে ফেলেছেন তা লাল রঙে (-) দেখাবে।
+
+এটি শুধুমাত্র সেই পরিবর্তনগুলোই দেখাবে যেগুলো আপনি git add করেছেন কিন্তু এখনো commit করেননি।
+
+5. View all changes (staged + unstaged) compared to last commit.
+
+    #include <bits/stdc++.h>
+    using namespace std;
+    +#define int long long
+
+    -int main()
+    +int32_t main()
+    {
+        int n;
+        int x, y, z;
+    @@ -9,10 +10,10 @@ int main() 
+    @@ -9,10 +10,10 @@ int main()
+
+        for (int i = 0; i < n; i++)
+        {
+    -        int x;
+    +        int x, count=0;
+    +        int y;
+            cin >> x;
+
+    -        int count = 0;
+            for (int j = 1; j * j <= x; j++)
+            {
+                if (x % j == 0)
+    (END)
+    # @@ -0,0 +1,36 @@: এর মানে ফাইলটি আগে খালি ছিল, এখন আপনি নতুন ১ থেকে ৩৬ নম্বর লাইন পর্যন্ত কোড যোগ   গছেন।
\ No newline at end of file
(END)
6. Create a new file, add content, commit it with a clear message.

    echo "This is a new file" > newfile.txt
    git add newfile.txt
    git commit -m "Add newfile.txt with initial content"
        or
    touch newfile.txt
    echo "This is a new file" >> newfile.txt (use >> to append otherwise it will overwrite mane dekhane na)
    git add newfile.txt
    git commit -m "Add newfile.txt with initial content"

7. Rename a tracked file using Git (should stage automatically).
    git mv oldname.txt newname.txt
    git commit -m "Rename oldname.txt to newname.txt"

    proved :
    $ git mv divisor.cpp change_divisor.cpp


Phase 2

১. আপনার ব্রাউজারে রিপোজিটরি খোলার জন্য:
আপনি যদি সরাসরি লিঙ্কে গিয়ে ফাইল বা ব্রাঞ্চ দেখতে চান, তবে এই কমান্ডটি দিলে আপনার ডিফল্ট ব্রাউজারে প্রজেক্টটি ওপেন হবে:

Bash

git remote -v
(এই কমান্ডটি দিলে আপনি আপনার রিপোজিটরির লিঙ্ক দেখতে পাবেন। সেটি কপি করে ব্রাউজারে পেস্ট করুন।)

২. রিমোট সার্ভারের ব্রাঞ্চগুলো দেখার জন্য:
সার্ভারে কী কী ব্রাঞ্চ আছে তা টার্মিনালেই দেখতে চাইলে লিখুন:

Bash

git branch -r
৩. সার্ভারের কোনো ব্রাঞ্চ নিজের কম্পিউটারে আনার জন্য (Checkout):
সার্ভারে থাকা কোনো ব্রাঞ্চে (যেমন sakif) কাজ করতে চাইলে সেটি আগে নিজের কম্পিউটারে ডাউনলোড করে নিতে হয়:

Bash

git checkout sakif
এই কমান্ডটি দিলে সার্ভারের sakif ব্রাঞ্চটি আপনার কম্পিউটারে চলে আসবে এবং আপনি তাতে কাজ করতে পারবেন।