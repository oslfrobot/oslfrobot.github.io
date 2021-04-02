function navbar() {
	var x = document.getElementById("link");
	if (x.style.display === "block") {
		x.style.display = "none";
	} else {
		x.style.display = "block";
	}
}

$(function () {
	$('a[href*="#"]:not([href="#"])').click(function () {
		if (location.pathname.replace(/^\//, '') == this.pathname.replace(/^\//, '') && location.hostname == this.hostname) {
			var target = $(this.hash);
			target = target.length ? target : $('[name=' + this.hash.slice(1) + ']');
			if (target.length) {
				$('html, body').animate({
					scrollTop: (target.offset().top)
				}, 800, "easeInOutExpo");
				return false;
			}
		}
	});

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
});