# memo

- 再帰で解く場合愚直な方法だと rowIndexが大きいとタイムアウトする
- 対策のために memoizeしたところ通った  
- https://faithandbrave.hateblo.jp/entry/20121210/1355126432
  - 構造体の `operator<` の実装は std::tieを使うと楽だった
