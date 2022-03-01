function solution(word) {
  const keyword = ['A', 'E', 'I', 'O', 'U'];
  let map = new Map();
  let index = 1;
  let DFS = (key) => {
      map.set(key.join(''), index++);
      if (key.length === 5)
          return;
      for (let i = 0; i < 5; i++) {
          key.push(keyword[i]);
          DFS(key);
          key.pop();
      }
  }
  for (let i = 0; i < 5; i++) {
      DFS([keyword[i]]);
  }
  return map.get(word);
}