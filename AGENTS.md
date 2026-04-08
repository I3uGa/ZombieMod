# Repository Guidelines

## Project Structure & Module Organization
Core plugin code lives in `src/`, with feature modules such as `zombiemod.cpp`, `zombiereborn.cpp`, and shared helpers under `src/utils/` and `src/cs2_sdk/`. Public headers are in `public/`. Runtime configs ship from `cfg/` and `configs/`; keep example files as `*.example`. Packaged game assets are in `assets/`, while editable source assets live in `assets_source/`. Build output goes to `build/`, and third-party code stays under `vendor/`, `sdk/`, and `CS2Fixes/`.

## Build, Test, and Development Commands
Initialize dependencies first:

```bash
git submodule update --init --recursive
```

Configure and build from `build/`:

```bash
python ../configure.py --enable-optimize --sdks cs2
ambuild
```

Windows typically uses `py ../configure.py ...` from an x64 Native Tools prompt. For containerized Linux builds, use `docker compose up`. Packaged server files are emitted to `build/package/cs2/`.

## Coding Style & Naming Conventions
This project is C++20. `.clang-format` is authoritative: use tabs, tab width 4, left-aligned pointers, and sorted includes. Format source before submitting:

```bash
bash clang-format.sh
```

Match existing naming: lowercase file names (`map_votes.cpp`), PascalCase types, and `g_`/`m_` style prefixes only where already established. Keep new files close to the feature they extend instead of creating broad utility buckets.

## Testing Guidelines
There is no standalone unit-test suite in this repository. Validation is build-based: confirm both `configure.py` and `ambuild` succeed, then smoke-test the generated package on a CS2 server when gameplay logic, configs, or assets change. Treat CI in `.github/workflows/build.yml` as the baseline expectation: successful Windows and Linux builds.

## Commit & Pull Request Guidelines
Recent history uses short, imperative subjects such as `Update SDK` and `Add proper ZR support...`. Keep commit titles concise, present tense, and focused on one change. Pull requests should describe gameplay or engine impact, note config or asset changes, link related issues, and include screenshots or server repro steps when UI, effects, or in-game behavior changes.

## Configuration & Packaging Notes
Do not edit generated output in `build/package/` directly; update source files in `cfg/`, `configs/`, `gamedata/`, or `assets/` instead. When adding distributable files, ensure `PackageScript` copies them into the correct `addons/cs2fixes` or `cfg/cs2fixes` destination.
