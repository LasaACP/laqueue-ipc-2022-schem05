{ pkgs }: {
	deps = [
		pkgs.parse-cli-bin
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}