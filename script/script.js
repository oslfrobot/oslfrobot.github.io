function navbar() {
	var x = document.getElementById("link");
	if (x.style.display === "block") {
		x.style.display = "none";
	} else {
		x.style.display = "block";
	}
}

document.addEventListener("DOMContentLoaded", function () {
	const height = document.getElementsByClassName("navbar")[0].clientHeight;

	new SmoothScroll('a[href*="#"]:not([href="#"])', {
		// easeInOutExpo
		speed: 800,
		speedAsDuration: true,
		offset: height < 60 ? height * -1 : (height - 60) * -1,
		customEasing: function (time) {
			if (time == 0) return 0;
			if (time == 1) return 1;
			if ((time /= 1 / 2) < 1) return 1 / 2 * Math.pow(2, 10 * (time - 1)) + 0;
			return 1 / 2 * (-Math.pow(2, -10 * --time) + 2) + 0;
		}
	});
});