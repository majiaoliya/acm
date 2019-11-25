
//整数二分模板
while(lef <= rig) {
	int mid = (lef + rig) >> 1;
	if(check(mid)) {
		ans = mid;
		lef = mid + 1;
	} else {
		rig = mid - 1;
	}
}


//double 二分模板
for(int i=0; i<100; i++) {
	double mid = (lef + rig) / 2;
	if(check(mid)) {
		ans = mid;
		lef = mid;
	} else {
		rig = mid;
	}
}

while(fabs(rig-lef) > eps) {
	double mid = (lef + rig) / 2;
	if(check(mid)) {
		ans = mid;
		lef = mid;
	} else {
		rig = mid;
   	}
}

