# memo

- 最小の要素の indexを探す
  - 2分探索で探す
- targetが最小の要素より小さい場合 falseを返す
- 場合分け
  - 最小値の indexが 0の場合, 通常の 2分探索を行う
  - targetが 0番目の要素より小さい場合, 最小値 indexから末尾の要素の間にあることになるので, その区間で 2分探索を行う
  - targetが 0番目の要素より大きい場合, 0から最小値 indexの区間で 2分探索を行う
