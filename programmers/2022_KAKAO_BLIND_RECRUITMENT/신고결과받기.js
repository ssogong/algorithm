function solution(id_list, report, k) {
    var answer = [];
    let ifReport = {};
    let cntReport = {};
    let reportName = {};
    for (let id of id_list) {
        cntReport[id] = 0;
        reportName[id] = [];
    }
    report.forEach(r => {
        if (ifReport[r] === 1)
            return;
        ifReport[r] = 1;
        let tmp = r.split(" ")
        cntReport[tmp[1]]++;
        reportName[tmp[0]].push(tmp[1]);
	})
    for (let id of id_list) {
        let cnt = 0;
        for (let re of reportName[id]) {
            if (cntReport[re] >= k)
                cnt++;
		}
        answer.push(cnt);
    }
    return answer;
}