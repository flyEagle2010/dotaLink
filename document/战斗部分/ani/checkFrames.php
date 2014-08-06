<?php
$dir = dir(".");
$s = [];
while (false !== ($f = $dir->read())) {
	if (substr($f, -4) != '.png') continue;
	if (preg_match("/ani_([0-9]+)_([^_]+)_([0-9]+)_([0-9]+)\.png/", $f, $m)) {
		$s[$m[1]][$m[2]][$m[3]][] = $m[4];
	} else {
		echo $f, "\n";
	}
}

$actions = ["idle", "attack01", "skill01", "walk"];
$directions = [2, 4, 6, 8];
foreach ($s as $heroId => $heroData) {
	$err = [];
	foreach ($actions as $act) {
		// 检测动作是否齐全
		if (!isset($heroData[$act])) {
			$err[] = "action non-exist:{$act}";
			continue;
		}
		$actData = $heroData[$act];
		foreach ($directions as $dr) {
			// 检测方向是否齐全
			if (!isset($actData[$dr])) {
				$err[] = "direction non-exist:{$act}_{$dr}";
				continue;
			}
			$frames = $actData[$dr];
			$drs[] = $dr;
			// 检测帧号是否从1连续
			for ($i = 1, $total = count($frames); $i <= $total; $i++) {
				$fr = sprintf("%02d", $i);
				if (!in_array($fr, $frames)) {
					$err[] = "frame non-exist:{$act}_{$dr}_{$fr}";
				}
			}
            //$err[] = "{$act}_{$dr}_{$total}";
		}
	}
	$result = empty($err) ? "ok" : implode("\n  ", $err);
	echo "heroId:{$heroId}: {$result}\n";
}
