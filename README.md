# LIMAP 

## TODO

* [ ] Port RANSAC to C++
* [ ] Change camera base class definition
* [ ] abstract Detection, Matching, Fitting and Merging 

## Dependencies
* Python 3.6 (just the version I am using, guess it is compatible to higher version)
* Eigen3
* COLMAP
* OpenCV >= 4.0 for pytlsd

```bash
git submodule update --init --recursive
python -m pip install -r requirements.txt
cd third-party/Hierarchical-Localization && python -m pip install -e . && cd ../..
mkdir -p build && cd build && cmake .. && make -j8 && cd ..
```

For SOLD2 line detector, the pretrained models need to be downloaded from the links provided in the [SOLD2 repo](https://github.com/cvg/SOLD2) and put into `core/detector/SOLD2/pretrained_models`.

## Quickstart

Download the test scene **(100 images)** with the following command.
```bash
bash scripts/quickstart.sh
```

To run **Fitnmerge** on Hypersim:
```bash
python runners/hypersim_fitnmerge.py
```

To run **Line Reconstruction** on Hypersim:
```bash
python runners/hypersim_triangulation.py
```
``-nv ${N_VISIBLE_VIEWS}`` is used to select lines that have enough supporting images for visualization.

``-nn ${N_NEIGHBORS}`` is used to determine number of neighbors (default: exhaustively matching all image pairs).
