files <- list.files("documents", full.names = TRUE)

# Iterate through each file
for (file in files) {
  rmarkdown::render(file)
}