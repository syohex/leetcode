# memo

- `grid` のすべての要素を 2重ループで見ていく
- `'1'` が登場したら一つの島を見つけたので, 結果を示す変数を `+1` する
- はじめに見つかった `1` から隣接する `1` は同一の島なので, 該当の点と隣接する `1` をすべて `0` に置き換える
- ループが最後まで到達したとき, 島の数が数え上げられていることになる
