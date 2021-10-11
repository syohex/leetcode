.PHONY: format clean

format:
	git ls-files | grep -E '\.(c|cpp|cc|h)$$' | xargs clang-format -i

clean:
	-find . \( -name '*.out' -o -name '*.exe' -o -name '*.lib' -o -name '*.exp' -o -name '*.pdb' \) -type f | xargs rm -f
	-find . -name '.vscode' -type d | xargs rm -rf

.PHONY: docker-setup docker-run docker-stop mysql-connect
docker-setup:
	sudo docker pull mysql

docker-run:
	sudo docker run --name mysql-leetcode -e MYSQL_ROOT_PASSWORD=test -d -p 3306:3306 mysql

docker-stop:
	sudo docker stop mysql-leetcode

mysql-connect:
	mysql -h localhost -P 3306 --protocol=tcp -uroot -p
