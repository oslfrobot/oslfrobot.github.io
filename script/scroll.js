document.addEventListener("DOMContentLoaded", function () {
	new SmoothScroll('a[href*="#"]:not([href="#"])', {
		// easeInOutExpo
		speed: 800,
		speedAsDuration: true,
		customEasing: function (x) {
			return x == 0 ? 0 : x == 1 ? 1 : x < 0.5 ? Math.pow(2, 20 * x - 10) / 2 : (2 - Math.pow(2, -20 * x + 10)) / 2
		}
	});
});