function solution(gems) {
    var answer = [0, Infinity];
    let gem_list = new Set(gems);
    let gem_flag = new Map();
    let gem_size = gem_list.size;
    let start = 0;
    let end = 0;
    let len = gems.length;
    gem_flag.set(gems[0], 1);
    while(start < len && end < len) {
       if (gem_flag.size == gem_size) {
           if (end - start < answer[1] - answer[0]) {
               answer = [start+1, end+1];
           }
           let tmpCnt = gem_flag.get(gems[start]);
           if (tmpCnt == 1)
               gem_flag.delete(gems[start]);
           else
               gem_flag.set(gems[start], tmpCnt - 1);
           start++;
       } else {
           end++;
           if (gem_flag.has(gems[end]))
               gem_flag.set(gems[end], gem_flag.get(gems[end])+1);
           else
               gem_flag.set(gems[end], 1);
       }
    }
    return answer;
}
console.log(solution(["XYZ"]));
//   console.log(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))