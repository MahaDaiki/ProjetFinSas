add:pull
	 git add .

push: commit
	git push

commit:add
	git commit -m "$(M)"

pull: fetch
	git pull

fetch:
	git fetch

run:
	gcc "$(F)" -o test && ./test


