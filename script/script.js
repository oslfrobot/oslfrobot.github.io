function navbar() {
	var x = document.getElementById("link");
	if (x.style.display === "block") {
		x.style.display = "none";
	} else {
		x.style.display = "block";
	}
}

$(function () {
	var url = window.location.pathname;
	var urlRegExp = new RegExp(url.replace(/\/$/, '') + "$");

	$('.navbar a').each(function () {
		if (urlRegExp.test(this.href.replace(/\/$/, ''))) {
			$(this).addClass('active');
			$(this).removeAttr("href");
		}
	});

	// $.getJSON('https://api.github.com/repos/oslfrobot/oslfrobot.github.io/commits', function (data) {
	// 	const hash = data[0].sha.slice(0, 8);

	// 	$('head link').each(function () {
	// 		this.href += "?v=" + hash;
	// 	});

	// 	$('head script').each(function () {
	// 		this.src += "?v=" + hash;
	// 	});
	// });

	var height = document.getElementsByClassName("navbar")[0].clientHeight;

	var scroll = new SmoothScroll('a[href*="#"]:not([href="#"])', {
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