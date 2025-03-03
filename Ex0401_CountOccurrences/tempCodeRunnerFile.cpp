	if(step == 1 && ((idx + step >= arr.size() || arr[idx + step] > x) && 
						 (idx - step < 0 || arr[idx - step] < x))) {
			break;
		}