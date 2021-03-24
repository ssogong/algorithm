function solution(s) {
  var answer = s.length;
  for (let i = 1; i < s.length; i++) {
      let p = 0;
      let q = p+i;
      let toMatch = s.slice(p, q);
      let cnt = 1;
      let tmpLength = s.length;
      while (p <= s.length-i && q <= s.length) {
          if (s.startsWith(toMatch, q)) {
              q += i;
              cnt += 1;
          }
          else {
              if (cnt > 1) {
                  tmpLength -= i * (cnt-1);
                  while (cnt > 0) {
                      tmpLength += 1;
                      cnt = Math.floor(cnt / 10);
                  }
              }
              p = q;
              q = p + i;
              toMatch = s.slice(p, q);
              cnt = 1;
          }
      }
      if (tmpLength < answer)
          answer = tmpLength;
  }
  return answer;
}
console.log(solution("xxxxxxxxxxyyy"))