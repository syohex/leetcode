# memo

- numsの各要素 numについて, num - 1の indexの位置に -1をかける
- 2つの値を持つ indexの要素は二度 -1をかけることで正に戻る
- 再度ループで先頭から見て, 正の値になっている abs(index + 1)を集めれば解となる
- 同じ要素を解に 2つ追加しないようチェックは必要となる
