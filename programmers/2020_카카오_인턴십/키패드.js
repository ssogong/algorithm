let map = {
  1: 'L',
  4: 'L',
  7: 'L',
  3: 'R',
  6: 'R',
  9: 'R'
};
let pos = {};
function dist(a, b) {
  return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
}
function solution(numbers, hand) {
  var answer = '';
  let left = '*';
  let right = '#';
  if (hand == 'left')
      hand = 'L';
  else 
      hand = 'R';
  for (let i = 0, num = 1; i < 3; i++) {
      for (let j = 0; j < 3; j++) {
          pos[num] = [i, j];
          num++;
      }
  }
  pos['*'] = [3, 0];
  pos['0'] = [3, 1];
  pos['#'] = [3, 2];
  for (let n of numbers) {
      let final = hand;
      if (map[n] != undefined) {
          if (map[n] == 'L')
              final = 'L';
          else
              final = 'R';
      } else {
          let distL = dist(pos[n], pos[left]);
          let distR = dist(pos[n], pos[right]);
          if (distL < distR) 
              final = 'L';
          else if (distL > distR)
              final = 'R';
      }
      answer += final;
      if (final == 'L')
          left = n;
      else
          right = n;
  }
  return answer;
}