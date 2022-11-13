mark=$1
git pull
git add *
git commit -m "$mark"
git push -u origin main
