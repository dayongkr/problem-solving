function solution(n, info) {
  const CASES = 3 ** 11;
  let maxDiff = 0;
  let result = [-1];
  let PEACHSCORE = 0;
  for (let i = 0; i < 11; i++) {
    if (info[i] !== 0) {
      PEACHSCORE += 10 - i;
    }
  }
  for (let i = 0; i < CASES; i++) {
    let brute = i;
    let shot = 0;
    let lionScore = 0,
      peachScore = PEACHSCORE;
    const archer = new Array(11).fill(0);
    for (let j = 0; j < 11; j++) {
      const type = brute % 3;
      const peachShot = info[j];
      // 0: 무승부, 1: 승, 2: 패
      switch (type) {
        case 0:
          shot += peachShot;
          archer[j] = peachShot;
          break;
        case 1:
          shot += peachShot + 1;
          archer[j] = peachShot + 1;
          lionScore += 10 - j;
          if (peachShot !== 0) {
            peachScore -= 10 - j;
          }
          break;
      }
      brute = Math.floor(brute / 3);
    }
    if (shot < n) {
      archer[10] += n - shot;
      shot = n;
    }
    const diff = lionScore - peachScore;
    if (shot === n && diff > 0 && diff >= maxDiff) {
      if (maxDiff === diff) {
        let canReplace = true;
        for (let j = 10; j >= 0; j--) {
          if (archer[j] > result[j]) {
            break;
          }
          if (archer[j] < result[j]) {
            canReplace = false;
            break;
          }
        }
        if (!canReplace) {
          continue;
        }
      }
      maxDiff = diff;
      result = archer;
    }
  }
  return result;
}
