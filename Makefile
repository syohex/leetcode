.PHONY: format clean

format:
	git ls-files | grep -E '\.(c|cpp|cc|h)$$' | xargs clang-format -i

clean:
	-find . -name 'a.out' -type f | xargs rm -f
	-find . -name '*.db' -type f | xargs rm -f
	-find . -name '.vscode' -type d | xargs rm -rf
