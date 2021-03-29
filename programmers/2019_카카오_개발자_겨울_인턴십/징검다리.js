// 03.25 못품
function solution(stones, k) {
  var answer = Infinity;
  for (let i = -1; i < stones.length - k; i += k) {
      let max = -1;
      for (let j = i+1; j <= i+k; j++) {
          if (stones[j] > max)
              max = stones[j];
      }
      if (answer > max)
          answer = max;
  }
  return answer;
}
console.log(solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3))
//console.log(solution([1], 1));