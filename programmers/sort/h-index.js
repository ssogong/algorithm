function solution(citations) {
  let idx = citations.sort((a, b) => b - a).findIndex((item, index) => item < index+1);
  return idx === -1 ? citations.length : idx;
}

console.log(solution(	[3, 0, 6, 1, 5]));