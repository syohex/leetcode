# memo

- 与えられた文字列を一文字ずつループ
- 開きカッコの場合スタックに積む
- 閉じカッコの場合
  - スタックが空 or スタックトップが対応するカッコでない場合は falseを返す
  - 対応するカッコの場合はスタックを popする
- 最後の文字まで繰り返し, 最終的にスタックが空であったら true, 空でないなら false
