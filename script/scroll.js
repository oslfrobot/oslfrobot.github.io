document.addEventListener("DOMContentLoaded", function () {
	new SmoothScroll('a[href*="#"]:not([href="#"])', {
		// easeInOutExpo
		speed: 800,
		speedAsDuration: true,
		customEasing: function (time) {
			if (time == 0) return 0;
			if (time == 1) return 1;
			if ((time /= 1 / 2) < 1) return 1 / 2 * Math.pow(2, 10 * (time - 1)) + 0;
			return 1 / 2 * (-Math.pow(2, -10 * --time) + 2) + 0;
		}
	});
});